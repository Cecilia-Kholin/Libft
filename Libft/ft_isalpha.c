/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:36:53 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/10 10:08:37 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// function returns zero if the character tests false and returns non-zero if the character tests true.
#include "libft.h"

int    ft_isalpha(int c)
{ 
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return 1;
    else 
        return 0;
}