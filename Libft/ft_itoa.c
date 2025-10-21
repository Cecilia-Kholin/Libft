/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:32:46 by usuario           #+#    #+#             */
/*   Updated: 2025/10/21 18:07:39 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////// INFORMACION /////////////////////////
//Utilizando malloc(3), genera una string que.        //
//represente el valor entero recibido como argumento. //
//Los números negativos tienen que gestionarse.       //
//NULL si falla la reserva de memoria.                //
////////////////////////////////////////////////////////

#include "libft.h"

static int	count_digits(int n)
{
	size_t	len;

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

static	char	*zero(int n, char *sol)
{
	long	nb;

	nb = n;
	if (nb == 0)
	{
		sol[0] = '0';
		sol[1] = '\0';
		return (sol);
	}
	return (sol);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	nb;
	char	*sol;

	nb = n;
	len = count_digits(nb);
	sol = (char *)malloc(len + 1);
	if (!sol)
		return (NULL);
	sol = zero(nb, sol);
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
