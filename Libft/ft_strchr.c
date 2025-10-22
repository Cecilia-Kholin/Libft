/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:52:08 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/22 10:02:37 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}
