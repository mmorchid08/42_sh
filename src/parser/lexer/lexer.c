/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:01:51 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/13 13:27:12 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_lexer	*lexer_init(char *line)
{
	t_lexer	*lex;

	lex = (t_lexer *)ft_malloc(sizeof(t_lexer));
	lex->tokens = vector_init(sizeof(t_token), del_token);
	lex->word = string_new();
	lex->line = line;
	lex->i = 0;
	lex->c = lex->line[lex->i];
	lex->quotes_stack = stack_new(sizeof(char), NULL);
	lex->backslash = FALSE;
	lex->is_word_complete = TRUE;
	return (lex);
}

static void	lexer_clean(t_lexer **lex)
{
	string_free((*lex)->word);
	ft_bzero(*lex, sizeof(t_lexer));
	ft_memdel((void **)lex);
}

static t_lexer_ret	*lexer_return(t_lexer **lex, t_bool is_interactive_mode)
{
	t_lexer_ret	*lex_ret;

	lex_ret = (t_lexer_ret *)ft_malloc(sizeof(t_lexer_ret));
	lex_ret->tokens = (*lex)->tokens;
	lex_ret->is_matched = TRUE;
	lex_ret->unmached_char = '\0';
	if ((*lex)->quotes_stack->length != 0)
	{
		lex_ret->is_matched = FALSE;
		lex_ret->unmached_char = *(char *)stack_peek((*lex)->quotes_stack);
	}
	else if (is_interactive_mode && (*lex)->backslash)
	{
		lex_ret->is_matched = (*lex)->backslash;
		lex_ret->unmached_char = BACK_SLASH;
	}
	if (is_interactive_mode == FALSE || lex_ret->is_matched == TRUE)
		lexer_clean(lex);
	return (lex_ret);
}

t_lexer_ret	*lexer(char *line, t_bool is_interactive_mode)
{
	static t_lexer	*lex = NULL;

	if (lex == NULL)
		lex = lexer_init(line);
	else
	{
		lex->line = line;
		lex->c = lex->line[lex->i];
	}
	while (lex->c)
	{
		if (lex->is_word_complete == FALSE)
			lexer_handle_word(lex);
		if (ft_isdigit(lex->c))
			lexer_handle_io_number(lex);
		if (lexer_is_word(lex->c))
			lexer_handle_word(lex);
		if (lex->word->length > 0 && lex->is_word_complete)
			lexer_push_token(lex, WORD);
		if (lexer_is_operator(lex->c))
			lexer_handle_operator(lex);
		lexer_skip_whitespaces(lex);
	}
	return (lexer_return(&lex, is_interactive_mode));
}
