/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:38:10 by maricamp          #+#    #+#             */
/*   Updated: 2025/09/30 15:38:13 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void    ft_memcpy(void *dest, const void *src, size_t n)
{
    int i;
    int j;

    i = 0;
    j = 0;

    while(i <= n)
    {
        if (j == i)
        {
            *((char *)dest + j) = *((char *)src + i);
            j++;
        }
        i++;
    }
}
#include <stdio.h>
int main()
{
    char src[] = "Hola mundo";
    char dest[20]; // suficiente espacio

    // probamos ft_memcpy
    ft_memcpy(dest, src, 7); // copiamos 11 bytes (incluyendo '\0')

    printf("src:  %s\n", src);
    printf("dest: %s\n", dest);

    return 0;
}
