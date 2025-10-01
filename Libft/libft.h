/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricamp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:55:14 by maricamp          #+#    #+#             */
/*   Updated: 2025/09/30 11:55:17 by maricamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h> // Incluir este archivo para size_t
#include <string.h> // Incluir este archivo para const de memcpy

size_t	ft_strlen(const char *str); // Se pone para poder usarlos en otras funciones 
size_t ft_strlcpy(char *dest, const char *src, size_t n);