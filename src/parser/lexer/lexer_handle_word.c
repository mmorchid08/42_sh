/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_handle_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:00:44 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/30 15:27:17 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	update_quoting(t_lexer *lex)
{
	if (lex->quote == SINGLE_QUOTE && lex->c == SINGLE_QUOTE)
		lex->quote = 0;
	else if (lex->quote == DOUBLE_QUOTE && lex->c == DOUBLE_QUOTE)
	{
		if (lex->backslash == FALSE)
			lex->quote = 0;
	}
	else if (lex->quote == 0 && lex->backslash == FALSE)
		lex->quote = lexer_quote_type(lex->c);
	if (lex->backslash)
		lex->backslash = FALSE;
	else
		lex->backslash = lex->c == BACK_SLASH && lex->quote != SINGLE_QUOTE;
}

static t_bool	lexer_is_command_start(t_vector *tokens_list)
{
	t_token last_token;

	if (tokens_list->length == 0)
		return (TRUE);
	last_token = ((t_token*)tokens_list->array)[tokens_list->length - 1];
	return (last_token.type == SEMI || last_token.type == AMPERSAND ||
		last_token.type == PIPE || last_token.type == OROR ||
		last_token.type == ANDAND);
}

static char	*temp_alias_get(char *word)
{
	if (ft_strequ(word, "ll"))
		return (ft_strdup("ls -l -a -F"));
	if (ft_strequ(word, "a"))
		return (ft_strdup("b"));
	if (ft_strequ(word, "cc"))
		return (ft_strdup("gcc && ./a.out && echo HI | cat -e; ll"));
	return (word);
}

static void	lexer_handle_alias(t_lexer *lex)
{
	char		*alias_subtitue;
	t_vector	*tmp_tokens;

	string_push(lex->word, '\0');
	alias_subtitue = temp_alias_get(lex->word->data);
	if (alias_subtitue == lex->word->data)
	{
		lexer_push_token(lex, WORD);
		return ;
	}
	tmp_tokens = lexer(alias_subtitue, FALSE);
	ft_strdel(&alias_subtitue);
	vector_insert_all(lex->tokens_list, tmp_tokens, lex->tokens_list->length);
	tmp_tokens->free_element = free;
	vector_free(tmp_tokens);
	lex->word->length = 0;
}

void		lexer_handle_word(t_lexer *lex)
{
	t_token_type	token_type;

	token_type = WORD;
	while (lex->c && lexer_is_word(lex->c, lex->quote || lex->backslash))
	{
		string_push(lex->word, lex->c);
		update_quoting(lex);
		lexer_advance(lex, 1);
	}
	if (token_type == WORD && lexer_is_command_start(lex->tokens_list) &&
			lex->enable_alias_subtitution == TRUE)
		lexer_handle_alias(lex);
	else
		lexer_push_token(lex, WORD);
}
