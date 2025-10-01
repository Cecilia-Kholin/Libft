/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:55:39 by maricamp          #+#    #+#             */
/*   Updated: 2025/09/30 10:55:40 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*memset - fill memory with a constant byte*/
/*La función memset de C *memset(void *str, int c, size_t n) copia el 
caracter c (un char sin signo) a los primeros n caracteres de str.*/
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		/*(char*)str cambia el puntero a char*/
		/*char solo avanza 1 byte*/
		/*int avanza 4 bytes, tendriamos como resultado 01, 01 ... que nos daría un numero raro*/
		*((char*)str + i) = c;
		i++;
	}
	return (str);
}
/*
#include <stdio.h> 
int main()
{
    char str[11] = "holaquetals";
    ft_memset(str, '4', 3);

    printf("%s", str);
}
*/
