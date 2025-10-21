/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:32:46 by usuario           #+#    #+#             */
/*   Updated: 2025/10/20 17:10:09 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////// INFORMACION /////////////////////////
//Utilizando malloc(3), genera una string que.        //
//represente el valor entero recibido como argumento. //
//Los números negativos tienen que gestionarse.       //
//NULL si falla la reserva de memoria.                //
////////////////////////////////////////////////////////

#include "libft.h"

static int count_digits(int n)
{
	size_t len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int n)
{
	size_t	len;
	long 	nb;
	char    *sol;

	nb = n;
	len = count_digits(nb);
	sol = (char *)malloc(len + 1);
	if (!sol)
		return (NULL);
	if (nb == 0)
	{
		sol[0] = '0';
		sol[1] = '\0';
		return (sol);
	}
	if (nb < 0)
	{
		sol[0] = '-';
		nb = -nb;
	}
	sol[len] = '\0';
	while (nb > 0)
	{
		sol[len - 1] = (nb % 10) + '0';
		len--;
		nb /= 10;
	}
	return (sol);
}
//int main(void)
//{
//	char *s;
//
//	s = ft_itoa(0);           printf("0 -> %s\n", s); 
//	s = ft_itoa(42);          printf("42 -> %s\n", s);
//	s = ft_itoa(235);          printf("235 -> %s\n", s);
//	s = ft_itoa(-12345);      printf("-12345 -> %s\n", s);
//	s = ft_itoa(-2147483648);     printf("-2147483648 -> %s\n", s);
//	s = ft_itoa(2147483647);     printf("2147483647 -> %s\n", s);
//	return 0;
//}