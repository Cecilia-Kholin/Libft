/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:39:28 by usuario           #+#    #+#             */
/*   Updated: 2025/10/02 11:31:08 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//0	string1 equivalente a string2
//Mayor que 0	string1 mayor que string2
//compara el ascii
//Compara o (111 en ASCII) vs p (112 en ASCII).
//Como 111 - 112 = -1
//printf("%d\n", strncmp("abc", "ab",  3)); // positivo (c > '\0')
#include "libft.h"

int ft_strncmp(const char *string1, const char *string2, size_t count)
{
    size_t i;
    size_t resultado;
    
    i = 0;
    //buscar el diferente si pones 3 busca diferentes hasta 3, pero si tuenes avc y awc se qeuda en el v
    while (i <= count)
    {
        if (string1[i] != string2[i]) //comparar caracteres, no punteros
        {
            return (int)((unsigned char)string1[i] - (unsigned char)string2[i]);
        }
        i++;
    }
    return (int)((unsigned char)string1[i] - (unsigned char)string2[i]);
}
#include <stdio.h> 
int main()
{
    char    *str1;
    char    *str2;
    int     resultado;

    str1 = "abc";
    str2 = "ab";
    resultado = ft_strncmp(str1, str2, 3);
    printf("%d\n", ft_strncmp("abc", "abc", 3)); // 0 (iguales)
    printf("%d\n", ft_strncmp("abc", "abd", 3)); // negativo (c < d) -1
    printf("%d\n", ft_strncmp("abd", "abc", 3)); // positivo (d > c) 1
    printf("%d\n", ft_strncmp("abc", "ab",  3)); // porque 'c' (99) - '\0' (0) = 99
    
}

//string1[i] es un carácter (char) de la cadena string1.
//Ej: si string1 = "hola", entonces string1[1] = 'o'.
//&string1[i] es la dirección de memoria de ese carácter (tipo const char *).
//Ej: &string1[1] apunta a la posición de memoria donde está 'o'.