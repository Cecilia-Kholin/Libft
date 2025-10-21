/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:32:46 by usuario           #+#    #+#             */
/*   Updated: 2025/10/21 14:32:35 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
//int	main(void)
//{
//	char	str1[] = "mundo disco";
//	char	str2[] = "HELLO";
//	char	str3[] = "abcdef";
//	char	str4[] = "12345";
//	char	str5[] = "";
//
//	printf("==== TESTS ft_striteri ====\n\n");
//
//	printf("Original : %s\n", str1);
//	ft_striteri(str1, to_upper_even);
//	printf("Mayusculas pares : %s  (esperado: FaNnY)\n\n", str1);
//
//	printf("Original : %s\n", str2);
//	ft_striteri(str2, to_lower);
//	printf("Todo minusculas  : %s  (esperado: hello)\n\n", str2);
//
//	printf("Original : %s\n", str3);
//	ft_striteri(str3, to_index_char);
//	printf("Reemplazar por índice : %s  (esperado: 012345)\n\n", str3);
//
//	printf("Original : %s\n", str4);
//	ft_striteri(str4, add_one);
//	printf("Avanza +1 cada char : %s  (esperado: 23456)\n\n", str4);
//
//	printf("Cadena vacía:\n");
//	ft_striteri(str5, to_upper_even);
//	printf("\"%s\" (esperado: \"\")\n\n", str5);
//
//	printf("Si no hubo crash con NULL → OK ✅\n");
//	ft_striteri(NULL, to_upper_even);  // no debe crashear
//	ft_striteri("hola", NULL);         // tampoco
//
//	printf("==============================\n");
//	return (0);
//}
