/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:36:48 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/20 11:54:29 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//crea una copia nueva de una cadena usando memoria dinámica.
/* Calcula la longitud de s (hasta '\0').
Reserva len + 1 bytes con malloc.
Copia los caracteres y añade el '\0' final.
Devuelve un puntero a la copia. Si falla la reserva → NULL. */
#include "libft.h"

char *ft_strdup(const char *string)
{
    size_t size;
    size_t i;
    char *copy;

    i = 0; 
    //calculamos la longitud
    size = ft_strlen(string);
    //reservamos esa cantidad para hacer la copia, + 1 para el \0
    copy = malloc(size + 1); //devuelve un puntero
    if (!copy)
		return (NULL);
    //hacemos la copia del string al return *copy
    while(i < size)
    {
        copy[i] = string[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
    
}
