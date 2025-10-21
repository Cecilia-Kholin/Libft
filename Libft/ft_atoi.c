/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:10:45 by usuario           #+#    #+#             */
/*   Updated: 2025/10/20 16:55:17 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *nptr)
{
	int i;
	int num;
	int sign;
	
	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == 9 || nptr[i] == 10 || nptr[i] == 11 || nptr[i] == 12 || nptr[i] == 13 || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += nptr[i] - '0';
		i++;
	}
	if ((nptr[i] >= 'A' && nptr[i] >= 'Z') || (nptr[i] >= 'a' && nptr[i] >= 'z'))
		return (num);
	return (num * sign);
}
//#include <stdlib.h>
//#include <stdio.h>
//int main()
//{
//    //Básicos
//    printf("---- TEST 1 ----\n");
//    printf("Input: \"42\"\n");
//    printf("atoi     = %d\n", atoi("42"));
//    printf("ft_atoi  = %d\n\n", ft_atoi("42"));
//
//    //Números negativos
//    printf("---- TEST 2 ----\n");
//    printf("Input: \"-42\"\n");
//    printf("atoi     = %d\n", atoi("-42"));
//    printf("ft_atoi  = %d\n\n", ft_atoi("-42"));
//
//    //Con espacios al principio
//    printf("---- TEST 3 ----\n");
//    printf("Input: \"   123\"\n");
//    printf("atoi     = %d\n", atoi("   123"));
//    printf("ft_atoi  = %d\n\n", ft_atoi("   123"));
//
//    //Con signos múltiples
//    printf("---- TEST 4 ----\n");
//    printf("Input: \"--123\"\n");
//    printf("atoi     = %d\n", atoi("--123"));
//    printf("ft_atoi  = %d\n\n", ft_atoi("--123"));
//
//    printf("Input: \"+-123\"\n");
//    printf("atoi     = %d\n", atoi("+-123"));
//    printf("ft_atoi  = %d\n\n", ft_atoi("+-123"));
//
//    //Con letras al final
//    printf("---- TEST 5 ----\n");
//    printf("Input: \"123abc\"\n");
//    printf("atoi     = %d\n", atoi("123abc"));
//    printf("ft_atoi  = %d\n\n", ft_atoi("123abc"));
//
//    //Con letras al principio
//    printf("---- TEST 6 ----\n");
//    printf("Input: \"abc123\"\n");
//    printf("atoi     = %d\n", atoi("abc123"));
//    printf("ft_atoi  = %d\n\n", ft_atoi("abc123"));
//
//    //Con número y espacios entre medias
//    printf("---- TEST 7 ----\n");
//    printf("Input: \"12 34\"\n");
//    printf("atoi     = %d\n", atoi("12 34"));
//    printf("ft_atoi  = %d\n\n", ft_atoi("12 34"));
//
//    //Con INT_MAX y INT_MIN
//    printf("---- TEST 8 ----\n");
//    printf("Input: \"2147483647\" (INT_MAX)\n");
//    printf("atoi     = %d\n", atoi("2147483647"));
//    printf("ft_atoi  = %d\n\n", ft_atoi("2147483647"));
//
//    printf("Input: \"-2147483648\" (INT_MIN)\n");
//    printf("atoi     = %d\n", atoi("-2147483648"));
//    printf("ft_atoi  = %d\n\n", ft_atoi("-2147483648"));
//
//    //Overflow (fuera de rango int)
//    printf("---- TEST 9 ----\n");
//    printf("Input: \"999999999999999999999\"\n");
//    printf("atoi     = %d\n", atoi("999999999999999999999"));
//    printf("ft_atoi  = %d\n\n", ft_atoi("999999999999999999999"));
//
//    printf("Input: \"-999999999999999999999\"\n");
//    printf("atoi     = %d\n", atoi("-999999999999999999999"));
//    printf("ft_atoi  = %d\n\n", ft_atoi("-999999999999999999999"));
//
//    //Solo signo o vacío
//    printf("---- TEST 10 ----\n");
//    printf("Input: \"+\"\n");
//    printf("atoi     = %d\n", atoi("+"));
//    printf("ft_atoi  = %d\n\n", ft_atoi("+"));
//
//    printf("Input: \"\"\n");
//    printf("atoi     = %d\n", atoi(""));
//    printf("ft_atoi  = %d\n\n", ft_atoi(""));
//
//    return 0;
//}