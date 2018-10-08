/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:03:22 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/03 02:18:40 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(char const *str, char c)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == c)
		{
			count++;
		}
	}
	if (str[i - 1] != c)
		count++;
	return (count);
}

static int		ft_word_len(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	if (str[i] == c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		w_counts;
	int		w_len;
	char	**words;

	if (s == NULL || c == 0)
		return (NULL);
	i = 0;
	w_counts = ft_word_count(s, c);
	words = (char**)malloc(sizeof(*words) * w_counts + 1);
	if (words == NULL)
		return (NULL);
	words[w_counts] = 0;
	while (w_counts--)
	{
		w_len = ft_word_len(s, c);
		words[i] = ft_strndup(s, w_len);
		s += w_len;
		i++;
	}
	return (words);
}
