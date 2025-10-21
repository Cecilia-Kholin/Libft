/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:48:48 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/21 10:36:54 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if(!dest && !src)
		return (NULL);
	unsigned char array_temporal[n];
	while (i < n)
	{
		array_temporal[i] = *((char *)src + i);
		i++;
	}
	while (j < n)
	{
		*((char *)dest + j) = array_temporal[j];
		j++;
	}
	return dest;
}
//#include <stdio.h> 
//int main()
//{
//    char src[] = "Hola Mundo";
//    char dest[20] = "Adios mundoyttyuty";
//    printf("dest antes: %s\n", dest);
//    ft_memmove(dest, src, 11);
//    printf("src:  %s\n", src);
//    printf("dest: %s\n", dest);
//    
//    return 0;
//}
