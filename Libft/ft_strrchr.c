/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:52:08 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/02 10:40:11 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Localiza la úlima posición del caracter 
//The last occurrence of p in 'computer program' is 'program'
#include "libft.h"

char *ft_strrchr(const char *string, int c)
{
    //guardar el puntero, si vemos otro c, actualizamos puntero
    size_t  i;
    char   *temporal;

    i = 0;
    while((unsigned char)string[i])
    {
        if ((unsigned char)string[i] == c)
        {
            temporal = (char *)&string[i];
        } 
        i++;
    }
    return (temporal);
}
#include <stdio.h> 
int main()
{
    char    *string;
    char    *resultado;

    string = "computer program";
    resultado = ft_strrchr(string, 'p');
    printf("resultado : %s\n", resultado);
}