/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:41:55 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/04 09:57:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static int	is_space(char c, int quote)
{
	return (ft_isspace(c) && !quote);
}

static char	set_quote(char c, char old_quote, char last_char)
{
	char	quote;

	quote = quote_type(c);
	if (old_quote == SINGLE_QUOTE && quote == SINGLE_QUOTE)
		return (0);
	else if (old_quote == DOUBLE_QUOTE && quote == DOUBLE_QUOTE
		&& last_char != BACK_SLASH)
		return (0);
	else if (old_quote == BACK_SLASH)
		return (0);
	else if (old_quote == 0)
		return (quote);
	return (old_quote);
}

static char	*get_word(char *str, size_t *i)
{
	t_string	*word;
	char		*res;
	size_t		w_index;
	char		quote;
	char		last_char;

	quote = 0;
	last_char = 0;
	w_index = 0;
	word = string_new();
	while (str[*i] && !is_space(str[*i], quote))
	{
		quote = set_quote(str[*i], quote, last_char);
		string_push(word, str[*i]);
		last_char = str[*i];
		++(*i);
		++(w_index);
	}
	res = string_get_data(word);
	string_free(word);
	return (res);
}

t_vector	*split(char *str, void (*free_element)(void *element))
{
	t_vector	*splitted_words;
	char		*word;
	size_t		i;

	i = 0;
	splitted_words = vector_init(sizeof(char *), free_element);
	while (str && str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i])
		{
			word = get_word(str, &i);
			vector_push(splitted_words, &word);
		}
	}
	return (splitted_words);
}

void	expand_args(t_vector *args_vec)
{
	t_vector	*splitted_words;
	char		**av;
	char		*word;
	char		*tmp;
	size_t		i;

	i = 0;
	av = args_vec->array;
	while (i < args_vec->length)
	{
		word = ft_strdup(av[i]);
		word = expand(word, NULL);
		tmp = ft_strtrim(word);
		splitted_words = split(tmp, NULL);
		free(word);
		free(tmp);
		vector_remove(args_vec, i);
		vector_insert_all(args_vec, splitted_words, i);
		i += splitted_words->length;
		vector_free(splitted_words);
	}
}
