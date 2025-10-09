/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:35:02 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/08 11:58:11 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Te devuelve el tamaño de src para saber si hay truncamiento
//se usa ft_strlen
#include <stdio.h> 
#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t n)
{
    size_t i = 0; // size_t usado para tamaños y conteos.
    int src_len;

    src_len = ft_strlen(src);
    while (i < n - 1 && src[i] != '\0') 
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 
    return (src_len);
}
//int main() {
//    char src[] = "Hola mundo";
//    char dest[20];
//    size_t ret = ft_strlcpy(dest, src, sizeof(dest));
//    printf("Test 1 - copia completa\n");
//    printf("src: %s\n", src);
//    printf("dest: %s\n", dest);
//    printf("ret: %zu\n", ret);
//    printf("------------\n");
//    char dest2[6];
//    size_t ret2 = ft_strlcpy(dest2, src, sizeof(dest2));
//    printf("Test 2 - truncamiento\n");
//    printf("src: %s\n", src);
//    printf("dest: %s\n", dest2);
//    printf("ret: %zu\n", ret2);
//    printf("------------\n");
//    char dest3[5] = "XXXX";
//    size_t ret3 = ft_strlcpy(dest3, src, 0);   
//    return 0;
//}