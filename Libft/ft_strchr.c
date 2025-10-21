/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:52:08 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/21 10:14:50 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strchr - locate first occurrence of a character in a string
 *
 * @str: pointer to a null-terminated string to be searched (const char *)
 * @c:   character to find, passed as int but compared as an unsigned char;
 *       the terminating '\0' is a valid search target
 *
 * Return: pointer to the first occurrence of the character in the string
 *         (char *). If the character is not found, returns NULL. If c is
 *         '\0', returns a pointer to the terminating null byte of str.
 *
 * Description:
 * Iterates through the string byte by byte and compares each character to c.
 * The function casts the string character to (unsigned char) for the
 * comparison to match the behavior of the standard strchr when handling
 * negative char values. When a match is found it returns a pointer to that
 * position in the original string; if no match is found and c is not '\0',
 * NULL is returned.
 *
 * Notes:
 * - The function signature returns a non-const char* even though the input
 *   is const char*. The caller should not modify the returned data if the
 *   original string is immutable.
 * - The comparison uses the byte value of c (i.e., (unsigned char)c).
 */
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}
/* #include <stdio.h> 
int main(void)
{
	char    *resultado;
	const char    *str;

	str = "hola mundo";
	resultado = ft_strchr(str, '3');

	printf("Resultado: %s\n", resultado);
	return 0;
} */