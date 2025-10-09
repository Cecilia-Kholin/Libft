/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:36:48 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/08 11:34:02 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char *ft_strjoin(char const *s1, char const *s2)
{
    //devuelve una nueva cadena, con s1 + s2
    //reservando en memoria
    size_t  len_s1;
    size_t  len_s2;
    size_t  total;
    size_t  j;
    size_t  i;
    char    *nuevacadena;

    len_s1 = 0;
    len_s2 = 0;
    j = 0;
    i = 0;
    while(s1[len_s1])
    {
        len_s1++;
    }
    while(s2[len_s2])
    {
        len_s2++;
    }
    total = len_s1 + len_s2;
    nuevacadena = malloc(total + 1);
    if (!nuevacadena)
		return (NULL);
    while(s1[i])
    {
        nuevacadena[i] = s1[i];
        i++;
    }
    while(s2[j])
    {
        nuevacadena[i + j] = s2[j];
        j++;
    }
    //realmete hace falta esto?? no teniamos una forma de ir a la ultima posicion? 
    nuevacadena[len_s1 + len_s2] = '\0';
    return(nuevacadena);    
}
#include <stdio.h>

int main()
{
    printf("%s\n", ft_strjoin("hola ", "mundo")); // hola mundo
    printf("%s\n", ft_strjoin("", "X"));          // X
    printf("%s\n", ft_strjoin("ABC", ""));        // ABC
}
