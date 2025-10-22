/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:38:10 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/22 09:59:44 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		if (j == i)
		{
			*((char *)dest + j) = *((char *)src + i);
			j++;
		}
		i++;
	}
	return (dest);
}
