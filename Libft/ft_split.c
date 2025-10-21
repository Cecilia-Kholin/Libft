/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:55:39 by maricamp          #+#    #+#             */
/*   Updated: 2025/10/21 16:40:33 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	len_word(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**free_all(char **v, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(v[i++]);
	free(v);
	return (NULL);
}

static void	copy_chars(char *dst, const char *src, size_t len)
{
	size_t	k;

	k = 0;
	while (k < len)
	{
		dst[k] = src[k];
		k++;
	}
	dst[len] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*total;
	size_t	countwords;
	size_t	len;
	size_t	i;

	i = 0;
	countwords = count_words (s, c);
	result = malloc(sizeof(char *) * (countwords + 1));
	if (!result)
		return (free_all(result, (int)i));
	while (i < countwords)
	{
		while (*s && *s == c)
			s++;
		len = len_word(s, c);
		total = malloc((sizeof(char)) * (len + 1));
		if (!total)
			return (free_all(result, (int)i));
		copy_chars(total, s, len);
		result[i++] = total;
		s += len;
	}
	result[countwords] = NULL;
	return (result);
}
