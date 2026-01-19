/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-al <pedde-al@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:44:04 by pedde-al          #+#    #+#             */
/*   Updated: 2026/01/15 12:06:42 by pedde-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str, char separator)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == separator)
			i++;
		if (str[i] && str[i] != separator)
			count++;
		while (str[i] && str[i] != separator)
			i++;
	}
	return (count);
}

static	char *get_next_word(char *str, char separator)
{
	static	int cursor;
	int		i;
	int		word_len;
	char	*next_str;

	cursor = 0;
	i = 0;
	word_len = 0;
	while (str[cursor] == separator)
		cursor++;
	while ((str[cursor + word_len] != separator) && (str[cursor + word_len]))
		word_len++;
	next_str = malloc(sizeof(char) * (word_len + 1));
	if (!next_str)
		return (NULL);
	while (str[cursor] != separator && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char separator)
{
	int		words;
	int		i;
	char	**res_str;

	words = count_words(str, separator);
	i = 0;
	res_str = malloc(sizeof(char *) * (words + 2));
	if (!res_str)
		return (NULL);
	while (words >= 0)
	{
		if (i == 0)
		{
			res_str[i] = malloc(sizeof(char));
			if (!res_str)
				return (NULL);
			res_str[i++][0] = '\0';
			continue ;
		}
		res_str[i++] = get_next_word(str, separator);
		words--;
	}
	res_str[i] = NULL;
	return (res_str);
}
