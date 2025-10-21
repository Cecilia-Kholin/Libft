/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:32:46 by usuario           #+#    #+#             */
/*   Updated: 2025/10/21 10:47:26 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////// INFORMACION /////////////////////////
// Aplica la función ’f’ a cada carácter de la cadena //
// ’s’, pasando su índice como primer argumento y el  //
// propio carácter como segundo argumento. Se crea una//
// nueva cadena (utilizando malloc(3)) para recoger.  //
// los resultados de las sucesivas aplicaciones de ’f’//   
////////////////////////////////////////////////////////
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t  i;
    size_t  len;
    char    *new_str;

    i = 0;
    len = 0;
    len = ft_strlen(s);
    new_str = (char *)malloc(len + 1);
    while (s[i])
    {
        new_str[i] = f(i, s[i]);
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
        
}
char	ft_test(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c - 32); // pasa a mayúscula en posiciones pares
	return (c);
}
//int	main(void)
//{
//	char *str = "mundo disco";
//	char *res = ft_strmapi(str, ft_test);
//
//	printf("Original: %s\n", str);
//	printf("Result:   %s\n", res);
//}