/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:52:08 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/08 16:32:48 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
 * @brief Converts a lowercase letter to its uppercase equivalent.
 *
 * This function takes an integer value representing an ASCII character.
 * If the character is a lowercase letter ('a' to 'z'), it returns the
 * corresponding uppercase letter. Otherwise, it returns the character unchanged.
 *
 * @param c The character to convert, represented as an int.
 * @return The uppercase equivalent if c is a lowercase letter, otherwise c unchanged.
 */
int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
    {
        c = c - ' ';
    }
    return (c);
}
#include <stdio.h> 
int main()
{
    int c = 'v';
    c = ft_toupper(c);
    printf("resultado %c\n", c);
}


