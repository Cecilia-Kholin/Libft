/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:28:32 by maricamp          #+#    #+#             */
/*   Updated: 2025/09/30 12:28:34 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*function sets the first n bytes of the area starting at s to zero*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{

	int	i;

	i = 0;
	while (i <= n)
	{
		*((char*)s + i) = 0;
		i++;
	}
}
/* #include <stdio.h> 
int main()
{
    char str[11] = "holaquetals";
    ft_bzero(str, 4);

    // imprimimos byte por byte
    for (int i = 0; i < 11; i++) {
        printf("%d ", str[i]); // cada byte debería ser 0
    }
    printf("\n");
} */
