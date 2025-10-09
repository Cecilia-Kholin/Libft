/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:32:46 by usuario           #+#    #+#             */
/*   Updated: 2025/10/08 21:07:11 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
//la diferencia con strmapi es que esta no crea una nueva string, sino que modifica la original
void    ft_striteri(char *s, void (*f)(unsigned int,char*))
{
    size_t  i;

    i = 0;
    while (s[i])
    {
        f(i, &s[i]); //& permite cambiar el valor del carácter en la posición
        i++;
    }
}
#include <stdio.h>
#include "libft.h"   // asegúrate de que ft_striteri está declarada aquí

// Función 1: Poner en mayúscula las letras de posiciones pares
void	to_upper_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - 32; // 'a'→'A', 'b'→'B', etc.
}

// Función 2: Pasar todo a minúscula
void	to_lower(unsigned int i, char *c)
{
	(void)i; // el índice no lo necesitamos
	if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

// Función 3: Reemplazar cada carácter por su índice (para ver visualmente)
void	to_index_char(unsigned int i, char *c)
{
	*c = '0' + (i % 10); // 0,1,2...9,0,1...
}

// Función 4: Avanzar el carácter en 1 (ej: 'a'→'b', 'b'→'c')
void	add_one(unsigned int i, char *c)
{
	(void)i;
	*c = *c + 1;
}

int	main(void)
{
	char	str1[] = "mundo disco";
	char	str2[] = "HELLO";
	char	str3[] = "abcdef";
	char	str4[] = "12345";
	char	str5[] = "";

	printf("==== TESTS ft_striteri ====\n\n");

	printf("Original : %s\n", str1);
	ft_striteri(str1, to_upper_even);
	printf("Mayusculas pares : %s  (esperado: FaNnY)\n\n", str1);

	printf("Original : %s\n", str2);
	ft_striteri(str2, to_lower);
	printf("Todo minusculas  : %s  (esperado: hello)\n\n", str2);

	printf("Original : %s\n", str3);
	ft_striteri(str3, to_index_char);
	printf("Reemplazar por índice : %s  (esperado: 012345)\n\n", str3);

	printf("Original : %s\n", str4);
	ft_striteri(str4, add_one);
	printf("Avanza +1 cada char : %s  (esperado: 23456)\n\n", str4);

	printf("Cadena vacía:\n");
	ft_striteri(str5, to_upper_even);
	printf("\"%s\" (esperado: \"\")\n\n", str5);

	printf("Si no hubo crash con NULL → OK ✅\n");
	ft_striteri(NULL, to_upper_even);  // no debe crashear
	ft_striteri("hola", NULL);         // tampoco

	printf("==============================\n");
	return (0);
}
