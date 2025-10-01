/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:52:08 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/01 12:52:11 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_toupper(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        c = c + ' ';
    }
    return (c);
}
#include <stdio.h> 
int main()
{
    int c = 'A';
    c = ft_toupper(c);
    printf("resultado %c\n", c);
}


