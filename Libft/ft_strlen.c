/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:51:39 by maricamp          #+#    #+#             */
/*   Updated: 2025/09/30 10:51:41 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*strlen - calculate the length of a string*/
/*Puedo usar la funcion en el memset*/
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

