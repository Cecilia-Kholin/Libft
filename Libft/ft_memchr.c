/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:32:46 by usuario           #+#    #+#             */
/*   Updated: 2025/10/02 12:38:49 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//devuelve un puntero, para eso (char *)&string[i]
//rastrea los primeros n bytes del área de memoria apuntada por s buscando el carácter c
//no dependen de cadenas con '\0'
//entonces el strchr busca en cadena, cuando cuentra c para toda la cadena desde C, 
//en cmabio en memchr solo encuentra ese byte, y solo devuelve ese, ninguna mas
#include "libft.h"
//Puedes ver los bytes de cualquier tipo usando un puntero a unsigned char.
void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;

    i = 0;
    while (i <= n)
    {
        if ( *((char*)s + i) == c)
        {
            return ((char *)s);
        }
        i++;
    }
    return (NULL);
}
#include <stdio.h> 
int main()
{
    char    *s;
    char    *sol;

    s = "abcdef";
    sol = ft_memchr(s, 'c',4);
    printf("resultado: %s\n", sol);
}
