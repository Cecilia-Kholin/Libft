/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:55:14 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/08 22:08:56 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // Incluir este archivo para size_t
#include <string.h> // Incluir este archivo para const de memcpy
#include <stdlib.h> // malloc, calloc, realloc, free
#include <stdint.h> //SIZEMAX
#include <unistd.h> // write, read, close

size_t	ft_strlen(const char *str); // Se pone para poder usarlos en otras funciones 
size_t ft_strlcpy(char *dest, const char *src, size_t n);
char *ft_strchr(const char *str, int c);
void *ft_memset(void *str, int c, size_t n);
void *ft_calloc(size_t number, size_t size);