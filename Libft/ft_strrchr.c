/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:52:08 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/22 10:03:10 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	size_t	i;
	char	*temporal;

	temporal = NULL;
	i = 0;
	while ((unsigned char)string[i] != '\0')
	{
		if ((unsigned char)string[i] == (unsigned char)c)
		{
			temporal = (char *)&string[i];
		}
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&string[i]);
	return (temporal);
}
