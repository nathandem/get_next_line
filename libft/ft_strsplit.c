/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:26:10 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 12:36:58 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

/*
** I love this `count_words` function, its continuous progression in the string
** only influenced by the separator and the `in_word` flag in the opposite
** state. That's cool.
*/

static int		count_words(char const *str, char sep)
{
	int				count;
	int				i;
	int				in_word;

	i = -1;
	count = 0;
	in_word = 0;
	while (str[++i])
	{
		if (str[i] != sep && !in_word)
		{
			count++;
			in_word = 1;
		}
		if (str[i] == sep && in_word)
			in_word = 0;
	}
	return (count);
}

static int		get_next_word_i(char const *s, int i, char sep)
{
	while (s[i] && s[i] != sep)
		i++;
	while (s[i] && s[i] == sep)
		i++;
	return (i);
}

static size_t	get_word_len(char const *s, char sep)
{
	size_t			i;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	return (i);
}

static void		free_allocated_words(char **words, int failure_index)
{
	int				j;

	j = 0;
	while (j < failure_index)
		free(words[j++]);
	free(words);
}

/*
** We set the `i` to the 1st word's index before entering the loop to cater
** for the case where there would be a word on the first index of the
** string. Had we wished to handle everything in the loop, we would have had
** to create add a `get_word_i` function to return the index of the first
** word even if this index is the current one of `i`, i.e. `0`.
**
** No need to add a terminating `0`to `words[j]` in the while loop as
** `ft_strnew` already takes care of putting a `0` at the end of the string.
*/

char			**ft_strsplit(char const *s, char c)
{
	char			**words;
	int				i;
	int				j;

	if (!s)
		return (NULL);
	if (!(words = (char**)malloc((count_words(s, c) + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (s[i] == c)
		i++;
	j = 0;
	while (s[i])
	{
		if ((words[j] = ft_strnew(get_word_len((s + i), c))) == NULL)
		{
			free_allocated_words(words, j);
			return (NULL);
		}
		ft_strncpy(words[j], (s + i), get_word_len((s + i), c));
		i = get_next_word_i(s, i, c);
		j++;
	}
	words[j] = 0;
	return (words);
}
