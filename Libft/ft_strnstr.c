/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:05:58 by usuario           #+#    #+#             */
/*   Updated: 2025/10/20 16:43:21 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
//#include <stdio.h>
//int main(void)
//{
//    const char *big    = "viaje antes que destino";
//    const char *little = "an";
//    char *res;
//
//    // Caso 1: len demasiado corto -> no lo encuentra
//    res = ft_strnstr(big, little, 4);
//    printf("len=4   -> %s\n", res ? res : "NULL");  
// esperado: NULL
//
//    // Caso 2: len suficiente -> lo encuentra
//    res = ft_strnstr(big, little, 100);
//    printf("len=100 -> %s\n", res ? res : "NULL");  
// esperado: "que destino"
//
//    // Caso 3: needle vacío -> devuelve big
//    res = ft_strnstr(big, "", 5);
//    printf("needle vacío -> %s\n", res);            
// esperado: "viaje antes que destino"
//
//    return 0;
//}