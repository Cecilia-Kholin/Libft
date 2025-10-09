/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:32:46 by usuario           #+#    #+#             */
/*   Updated: 2025/10/08 20:18:51 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////// INFORMACION /////////////////////////
//Utilizando malloc(3), genera una string que.        //
//represente el valor entero recibido como argumento. //
//Los números negativos tienen que gestionarse.       //
//NULL si falla la reserva de memoria.                //
////////////////////////////////////////////////////////

#include <stdio.h>
#include "libft.h"

static int count_digits(int n)
{
    size_t len;

    len = 0;
    if (n < 0)
    {
        len++; // espacio para el signo negativo
        n = -n; //hacemos positivo el número para contar los dígitos
    }
    while (n != 0) //conteo
    {
        n = n / 10;
        len++;
    }
    return (len);
}
char *ft_itoa(int n)
{
    size_t len;
    long nb; // Usamos long para manejar el caso de -2147483648
    char    *sol;

    nb = n; //nb para conteo
    len = count_digits(nb);
    sol = (char *)malloc(len + 1);
    if (!sol)
        return (NULL);
    if (nb < 0)
    {
        sol[0] = '-';
        nb = -nb; //hacemos positivo el número para contar los dígitos
    }
    // caso especial
    if (nb == 0)
    {
        sol[0] = '0';
        sol[1] = '\0';
        return (sol);
    }
    sol[len] = '\0';
    // Bucle para rellenar desde el final hacia el inicio
    while (nb > 0)
    { // % --> devuleve el resto. 
        sol[len - 1] = (nb % 10) + '0'; //apuntar al carácter anterior a la posición del ∖0 que ya reservaste.
        len--; // Retrocedemos el índice
        nb /= 10;
    }
    return (sol);
}
int main(void)
{
	char *s;

	s = ft_itoa(0);           printf("0 -> %s\n", s); 
	s = ft_itoa(42);          printf("42 -> %s\n", s);
	s = ft_itoa(235);          printf("235 -> %s\n", s);
	s = ft_itoa(-12345);      printf("-12345 -> %s\n", s);
	s = ft_itoa(-2147483648);     printf("-2147483648 -> %s\n", s);
	s = ft_itoa(2147483647);     printf("2147483647 -> %s\n", s);
	return 0;
}