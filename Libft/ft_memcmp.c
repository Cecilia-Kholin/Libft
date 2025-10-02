/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:54:42 by usuario           #+#    #+#             */
/*   Updated: 2025/10/02 15:05:23 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
    //compara hasta encontrar el primer valor diferente
    //compara hasta n
    i = 0;
    while (i < n)
    {
        if (*((unsigned char*)s1 + i) !=  *((unsigned char*)s2 + i))
        {
            return (*((unsigned char*)s1 + i) -  *((unsigned char*)s2 + i));
        }
        i++;
    }
    return (0);
}

int main()
{
     printf("=== TESTS memcmp ===\n");

    // 1) Dos cadenas iguales
    char a1[] = "hola";
    char a2[] = "hola";
    printf("1) memcmp(\"%s\",\"%s\",4) = %d\n", a1, a2, ft_memcmp(a1,a2,4));
    // esperado: 0

    // 2) Diferencia en el primer carácter
    char b1[] = "hola";
    char b2[] = "bola";
    printf("2) memcmp(\"%s\",\"%s\",4) = %d\n", b1, b2, ft_memcmp(b1,b2,4));
    // esperado: 'h' (104) - 'b' (98) = positivo (>0)

    // 3) Diferencia más adelante
    char c1[] = "hola";
    char c2[] = "hula";
    printf("3) memcmp(\"%s\",\"%s\",4) = %d\n", c1, c2, ft_memcmp(c1,c2,4));
    // esperado: 'o' (111) - 'u' (117) = negativo (<0)

    // 4) Comparar solo los primeros n bytes
    char d1[] = "hola";
    char d2[] = "hombre";
    printf("4) memcmp(\"%s\",\"%s\",2) = %d\n", d1, d2, ft_memcmp(d1,d2,2));
    // esperado: 0 (porque 'h' y 'o' coinciden en los 2 primeros)

    // 5) Con números en un array
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {1, 2, 3, 5};
    int r = ft_memcmp(arr1, arr2, sizeof(arr1));
    printf("5) memcmp(arr1, arr2, sizeof) = %d\n", r);
    // esperado: negativo porque 4 < 5

    // 6) Caso especial: n=0 → siempre 0
    printf("6) memcmp(\"abc\",\"xyz\",0) = %d\n", ft_memcmp("abc","xyz",0));
    // esperado: 0

    return 0;
}