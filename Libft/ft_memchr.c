/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:32:46 by usuario           #+#    #+#             */
/*   Updated: 2025/10/02 13:06:38 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//devuelve un puntero, para eso (char *)&string[i]
//rastrea los primeros n bytes del área de memoria apuntada por s buscando el carácter c
//no dependen de cadenas con '\0'
//entonces el strchr busca en cadena, cuando cuentra c para toda la cadena desde C, 
//en cmabio en memchr solo encuentra ese byte, y solo devuelve ese, ninguna mas
#include "libft.h"
//Puedes ver los bytes de cualquier tipo usando un puntero a unsigned char.
void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;

    i = 0;
    while (i <= n)
    {
        if ( *((unsigned char*)s + i) == (unsigned char)c  && i < n)
        {
            return ((char *)&s[i]);
        }
        i++;
    }
    return (NULL);
}
#include <stdio.h> 

#include <stdio.h>
#include <string.h> // memset, memchr

int main(void)
{
    char s1[] = "abcdef";
    char *res;

    printf("=== TESTS ft_memchr ===\n");

    // 1) Buscar 'c' en los primeros 4 bytes
    res = ft_memchr(s1, 'c', 4);
    if (res)
        printf("1) encontrado: %s\n", res);  // esperado: "cdef"
    else
        printf("1) NO encontrado\n");

    // 2) Buscar 'c' en los 2 primeros bytes (no debe encontrarlo)
    res = ft_memchr(s1, 'c', 2);
    if (res)
        printf("2) encontrado: %s\n", res);
    else
        printf("2) NO encontrado (ok)\n");

    // 3) Buscar '\0' (terminador de string) en rango grande
    res = ft_memchr(s1, '\0', sizeof(s1));
    if (res)
        printf("3) encontrado terminador en índice %ld\n", res - s1);

    // 4) Buscar un carácter que no existe
    res = ft_memchr(s1, 'z', 6);
    if (res)
        printf("4) encontrado: %s\n", res);
    else
        printf("4) NO encontrado (ok)\n");

    // 5) Buscar en n = 0 (no busca nada)
    res = ft_memchr(s1, 'a', 0);
    if (res)
        printf("5) encontrado: %s\n", res);
    else
        printf("5) NO encontrado (ok)\n");

    // 6) Buscar un byte no imprimible
    unsigned char raw[] = {0x10, 0x20, 0x7E, 0x00, 0xFF};
    unsigned char *res2 = ft_memchr(raw, 0x7E, sizeof(raw));
    if (res2)
        printf("6) encontrado 0x7E en índice %ld\n", res2 - raw);
    else
        printf("6) NO encontrado\n");

    return 0;
}
//=== TESTS memchr ===
//1) encontrado: cdef
//2) NO encontrado (ok)
//3) encontrado terminador en índice 6
//4) NO encontrado (ok)
//5) NO encontrado (ok)
//6) encontrado 0x7E en índice 2