/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:10:45 by usuario           #+#    #+#             */
/*   Updated: 2025/10/06 09:50:09 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
//pasa el digito a int
int ft_atoi(const char *nptr)
{
    int i;
    int num;
    int sign;
    
    i = 0;
    num = 0;
    sign = 1;
    while (nptr[i] == ' ')
    {
        i++;
    }
    if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        // *10 y - 0
        num *= 10;
        num += nptr[i] - '0';
        i++;
    }
    if (nptr[i] >= 'A' && nptr[i] >= 'Z' || nptr[i] >= 'a' && nptr[i] >= 'z' )
    {
        return (num);
    }
    return (num * sign);
}

int main()
{
    char    *caracter;
    int num;
    
    caracter = "123";

    num = ft_atoi (caracter);
    printf("int: %d\n", num);
    printf("aoti: %d\n", ft_atoi("   123"));
    printf("int: %s\n", "+42abc");
	printf("aoti: %d\n", atoi("\t\n+42abc"));
    printf("int: %s\n", "0007");
	printf("aoti: %d\n", atoi("0007"));
    printf("int: %s\n", "-0");
	printf("aoti: %d\n", atoi("-0"));
}
