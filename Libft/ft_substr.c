/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:36:48 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/22 10:04:31 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check_start(unsigned int start, size_t len)
{
	char	*reservado;

	if ((size_t)start >= len)
	{
		reservado = malloc(1);
		if (!reservado)
			return (NULL);
		reservado[0] = '\0';
		return (reservado);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_str;
	size_t	total;
	size_t	j;
	char	*result;

	j = 0;
	if (!s)
		return (NULL);
	len_str = ft_strlen(s);
	result = check_start(start, len_str);
	if (result)
		return (result);
	total = len_str - (size_t)start;
	if (total > len)
		total = len;
	result = (char *)malloc(total + 1);
	if (!result)
		return (NULL);
	while (j < total)
	{
		result[j] = s[(size_t)start + j];
		j++;
	}
	result[j] = '\0';
	return (result);
}
