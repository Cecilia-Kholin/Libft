/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:55:39 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/09 11:33:33 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// max 25 lineas 
// MALLOC
//      PUNTEROS:   MALLOC(SIZEOF(CHAR*) * (PALABRA + 1)).  NULL ES EL +1
//  CADA PALABRA:   MALLOC(SIZEOF(CHAR) * (LON_PALABRA + 1)) \0 ES EL +1
//conocer el número de filas (palabras)
#include "libft.h"

static int count_words(const char *s, char c)
{
    int count = 0;
    int in_word = 0; // 0 = fuera de palabra, 1 = dentro de palabra

    while (*s)
    {
        if (*s == c)          // si es el delimitador
            in_word = 0;      // salimos de una palabra
        else if (in_word == 0) // si no es delimitador y veníamos de fuera
        {
            in_word = 1;      // empezamos nueva palabra
            count++;          // ¡contamos!
        }
        s++; // avanzamos el puntero
    }
    return count;
}
//conocer la longitud de cada palabra, por separado
static size_t   len_word(const char *s, char c)
{
    size_t  len;

    len = 0;
    while(s[len] && s[len] != c)
        len++;
    return(len);
}
static void free_all(char **v, int n)
{
    int i = 0;
    while (i < n)
        free(v[i++]); // libera cada palabra individual
    free(v);          // libera el array de punteros
}
// copia len chars de src a dst y cierra en '\0'
static void copy_chars(char *dst, const char *src, size_t len)
{
    size_t k = 0;
    while (k < len)
    {
        dst[k] = src[k];
        k++;
    }
    dst[len] = '\0';
}

/////////////// FUNCIÓN SPLIT ///////////////
char **ft_split(char const *s, char c)
{
    char    **result;
    char    *total;
    char    *copiar;
    size_t  countwords;
    size_t  i;

    i = 0;
    if (!s)
        return (NULL);
    countwords = count_words(s, c);
    result = malloc(sizeof(char*) * (countwords + 1));
    while (i < countwords)//ir añadiento cada palabra al total
    {
        size_t  len;
        while (*s && *s == c) //saltar delimitadores físicos antes de medir (aunque lo tengo en el count word no srive para usarlo aqui)
            s++;
        len = len_word(s, c);       // 2) mide la palabra actual
        total = malloc((sizeof(char)) * (len + 1)); // 3) reserva len + 1
        if (!total) 
        { 
            free_all(result, i); 
            return NULL; 
        }
        copy_chars(total, s, len); // <-- tu helper con while
        result[i++] = total;
        i++;
        s += len; //avanzo s tras copiar
    }
    result[countwords] = NULL; //añadimos el NULL del final 
    return result;
}

/////////////////////////////////
/////////    TESTS    ///////////
/////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"   // tu ft_split debe estar declarado aquí

static void print_split(char **v)
{
    int i = 0;
    if (!v)
        return;
    while (v[i])
    {
        printf("[%s]", v[i]);
        if (v[i + 1])
            printf(" ");
        i++;
    }
    printf("\n");
}

int main(void)
{
    char **res;

    // 1️⃣ caso normal
    res = ft_split("hola mundo disco", ' ');
    printf("Caso 1 -> ");
    print_split(res);          // esperado: [hola] [mundo] [disco]
    // libera memoria
    for (int i = 0; res && res[i]; i++) free(res[i]);
    free(res);

    // 2️⃣ delimitadores seguidos
    res = ft_split("uno,,dos,,,tres", ',');
    printf("Caso 2 -> ");
    print_split(res);          // esperado: [uno] [dos] [tres]
    for (int i = 0; res && res[i]; i++) free(res[i]);
    free(res);

    // 3️⃣ delimitadores al inicio y fin
    res = ft_split("  **42**Madrid***", '*');
    printf("Caso 3 -> ");
    print_split(res);          // esperado: [42] [Madrid]
    for (int i = 0; res && res[i]; i++) free(res[i]);
    free(res);

    // 4️⃣ cadena vacía
    res = ft_split("", ',');
    printf("Caso 4 -> ");
    print_split(res);          // esperado: (sin salida)
    free(res);

    // 5️⃣ solo delimitadores
    res = ft_split("*****", '*');
    printf("Caso 5 -> ");
    print_split(res);          // esperado: (sin salida)
    free(res);

    // 6️⃣ sin delimitador presente
    res = ft_split("libft", ',');
    printf("Caso 6 -> ");
    print_split(res);          // esperado: [libft]
    for (int i = 0; res && res[i]; i++) free(res[i]);
    free(res);

    return 0;
}