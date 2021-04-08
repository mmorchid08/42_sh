/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_handle_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:00:44 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/08 18:21:11 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	identify_expansions(t_lexer *lex)
{
	char	*el;
	char	next_char;

	if (lex->quotes_stack->length > 0)
	{
		el = (char *)stack_peek(lex->quotes_stack);
		if (*el == '{' && lex->c == '}')
			stack_pop(lex->quotes_stack);
		if (*el == '(' && lex->c == ')')
			stack_pop(lex->quotes_stack);
		return ;
	}
	if (lex->c == '(')
		stack_push(lex->quotes_stack, &(lex->c));
	else if (lex->c == '$')
	{
		next_char = lex->line[lex-> i + 1];
		if (next_char == '(' || next_char == '{')
		{
			stack_push(lex->quotes_stack, &next_char);
			string_push(lex->word, next_char);
			lexer_advance(lex, 1);
		}
	}
}

static	void	update_quotes_stack(t_lexer *lex)
{
	char	*el;

	el = (char *)stack_peek(lex->quotes_stack);
	if (el && *el == SINGLE_QUOTE)
	{
		if (lex->c == SINGLE_QUOTE)
			stack_pop(lex->quotes_stack);
		return ;
	}
	if (lex->backslash == TRUE)
		return ;
	identify_expansions(lex);
	if (el && *el == DOUBLE_QUOTE && lex->c == DOUBLE_QUOTE)
		stack_pop(lex->quotes_stack);
	if (el && (*el == SINGLE_QUOTE || *el == DOUBLE_QUOTE))
		return ;
	else if (lex->c == SINGLE_QUOTE || lex->c == DOUBLE_QUOTE)
		stack_push(lex->quotes_stack, &(lex->c));
}

static void	update_backslash(t_lexer *lex)
{
	char	*last_stack_el;

	last_stack_el = (char *)stack_peek(lex->quotes_stack);
	if (last_stack_el && *last_stack_el == SINGLE_QUOTE)
		return ;
	lex->backslash = !lex->backslash && lex->c == BACK_SLASH;
}

static t_bool	is_word_delimeter(t_lexer *lex)
{
	char	*last_el;

	last_el = (char *)stack_peek(lex->quotes_stack);
	if (lexer_is_word(lex->c))
		return (FALSE);
	return (lex->backslash == FALSE && (!last_el || *last_el == '\0'));
}

void	lexer_handle_word(t_lexer *lex)
{
	lex->quotes_stack = stack_new(sizeof(char), free);
	lex->backslash = FALSE;
	while (lex->c && !is_word_delimeter(lex))
	{
		string_push(lex->word, lex->c);
		update_quotes_stack(lex);
		update_backslash(lex);
		lexer_advance(lex, 1);
	}
	lex->is_word_complete = lexer_is_word_complete(lex);
	if (lex->is_word_complete)
		lexer_push_token(lex, WORD);
}
