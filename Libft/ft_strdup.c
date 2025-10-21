/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:36:48 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/21 17:05:04 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	size_t	size;
	size_t	i;
	char	*copy;

	i = 0;
	size = ft_strlen(string);
	copy = malloc(size + 1);
	if (!copy)
		return (NULL);
	while (i < size)
	{
		copy[i] = string[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
