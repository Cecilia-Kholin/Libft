/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:36:48 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/08 12:01:17 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
   size_t	strat;
	size_t	end;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		strat = 0;
		end = ft_strlen(s1);
		while (s1[strat] && ft_strchr(set, s1[strat]))
			strat++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > strat)
			end--;
		str = (char *)malloc(sizeof(char) * (end - strat + 1));
		if (str)
			ft_strlcpy(str, &s1[strat], end - strat + 1);
	}
	return (str);
}
//include <stdio.h>
//nt	main(void)
//
//	char *result;
//	// Test 1: elimina guiones y asteriscos
//	result = ft_strtrim("--**Hello**--", "-*");
//	printf("1. --**Hello**-- '%s'\n", result);
//	free(result);
//	// Test 2: elimina espacios
//	result = ft_strtrim("   Hola mundo   ", " ");
//	printf("2.    Hola mundo   '%s'\n", result);
//	free(result);
//	// Test 3: elimina caracteres al principio y al final
//	result = ft_strtrim("xx42Madridxx", "x");
//	printf("3. xx42Madridxx'%s'\n", result);
//	free(result);
//	// Test 4: todo se recorta
//	result = ft_strtrim("xxxx", "x");
//	printf("4. xxxx'%s'\n", result);
//	free(result);
//
//	// Test 5: sin caracteres a eliminar
//	result = ft_strtrim("Libft", "");
//	result = ft_strtrim("Libft", "");
//	printf("5. '%s'\n", result);
//	free(result);
//
//	// Test 6: cadena vacía
//	result = ft_strtrim("", "abc");
//	printf("6. '%s'\n", result);
//	free(result);
//
//	return (0);
//
