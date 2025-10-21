/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:39:28 by usuario           #+#    #+#             */
/*   Updated: 2025/10/21 16:54:37 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t count)
{
	size_t	i;

	if (count == 0)
		return (0);
	i = 0;
	while (i + 1 < (unsigned char)count && string1[i] && string2[i])
	{
		if (string1[i] != string2[i])
		{
			return ((unsigned char)string1[i] - (unsigned char)string2[i]);
		}
		i++;
	}
	return ((unsigned char)string1[i] - (unsigned char)string2[i]);
}
