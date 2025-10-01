/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <maricamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:14:54 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/01 12:54:27 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//si n es menor que len de dest no copia nada, solo se agura que acabe en \0
#include <stdio.h> 
#include "libft.h"

size_t strlcat(char *dst, const char *src, size_t n)
{
    size_t i = 0; 
    int dst_len;

    dst_len = ft_strlen(dst);

    if (n > dst_len)
    {
        while (src[i] != '\0' && dst_len < n)
        {
            dst[dst_len++] = src[i++];
        }
        dst[dst_len] = '\0';
    }
    else
    {
        while (i < n)
        {
            dst[i++];
        }  
        dst[i] = '\0';
    }
    
    dst_len = ft_strlen(dst);
    return (dst_len);
}
int main() {
    char src[] = "mundo";
    char dest[] = "hola";

    printf("src antes: %s\n", src);
    printf("dest antes: %s\n", dest);
    size_t ret = strlcat(dest, src, 3);
    
    printf("src: %s\n", src);
    printf("dest: %s\n", dest);
    printf("ret: %zu\n", ret);
}