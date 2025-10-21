/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:36:48 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/21 14:51:21 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	j;
	size_t	i;
	char	*nuevacadena;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	j = 0;
	i = 0;
	nuevacadena = malloc((len_s1 + len_s2) + 1);
	if (!nuevacadena)
		return (NULL);
	while (s1[i])
	{
		nuevacadena[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		nuevacadena[i + j] = s2[j];
		j++;
	}
	nuevacadena[len_s1 + len_s2] = '\0';
	return (nuevacadena);
}
