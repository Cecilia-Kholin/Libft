/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:14:54 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/21 17:04:54 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;
	size_t	len_dst_initial;

	i = 0;
	len_dst_initial = ft_strlen(dst);
	len_src = ft_strlen(src);
	len_dst = len_dst_initial;
	if (len_dst >= n)
	{
		return (n + len_src);
	}
	while (len_dst < n - 1 && src[i] != '\0')
	{
		dst[len_dst++] = src[i++];
	}
	dst[len_dst] = '\0';
	return (len_dst_initial + len_src);
}
