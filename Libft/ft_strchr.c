/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:52:08 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/01 12:52:11 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
// buscar la primera aparición de un carácter específico dentro de una cadena de texto
char *strchr(const char *s, int c)
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {
        if (s[i] == c)
        {
            return ((char *)s); 
        }
        i++;
    }
}
#include <stdio.h> 

int main ()
{
    char s[] = "holamundo";
    char *resultado_ptr;

    resultado_ptr = ft_strchr(s, 'm');
    printf("resultado %s\n", resultado_ptr);
}
