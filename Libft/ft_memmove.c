/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:48:48 by maricamp          #+#    #+#             */
/*   Updated: 2025/09/30 16:48:52 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned int i;
    unsigned int j;

    i = 0;
    j = 0;
    //crear array temporal, tamaño del src
    unsigned char array_temporal[n];
    //pasarle la informacion de src
    while (i < n)
    {
        array_temporal[i] = *((char *)src + i); 
        i++;
    }
    //pasar informacion del array al destino
    while (j < n)
    {
        *((char *)dest + j) = array_temporal[j];
        j++;
    }
    return dest;
}
#include <stdio.h> 
int main()
{
    char src[] = "Hola Mundo";
    char dest[20] = "Adios mundoyttyuty";
    printf("dest antes: %s\n", dest);
    ft_memmove(dest, src, 11);
    printf("src:  %s\n", src);
    printf("dest: %s\n", dest);
    
    return 0;
}
