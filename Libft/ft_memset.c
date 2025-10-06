/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:55:39 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/06 14:53:30 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La función memset de C *memset(void *str, int c, size_t n) copia el 
caracter c (un char sin signo) a los primeros n caracteres de str.*/
/*(char*)str cambia el puntero a char*/
/*char solo avanza 1 byte*/
/*int avanza 4 bytes, tendriamos como resultado 01, 01 ... que nos daría un numero raro*/
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char*)str + i) = (unsigned char)c;
		i++;
	}
	return (str);
}
/* #include <stdio.h> 
int main()
{
    char str[15] = "holaquetals";
    ft_memset(str, '4', 3);

    printf("%s\n", str);
//------------------
	char buffer[10];

    // Rellenar los 10 bytes con el valor 'A'
    ft_memset(buffer, 'A', 10);

    for (int i = 0; i < 10; i++) {
        printf("%c ", buffer[i]);
    }
} */