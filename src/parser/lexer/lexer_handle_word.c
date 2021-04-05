/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_handle_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:00:44 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/05 19:00:41 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	identify_expansions(t_lexer *lex, t_stack *st)
{
	char *el;
	char next_char;

	el = (char *)stack_peek(st);
	if (el && *el == '{' && lex->c == '}')
		stack_pop(st);
	if (el && *el == '(' && lex->c == ')')
		stack_pop(st);
	if (lex->c == '\'' && (!el || *el == '\0'))
	next_char = lex->line[lex->i + 1];
	if (lex->c == '$' && (next_char == '{' || next_char == '('))
		stack_push(st, &next_char);
}

static void update_stack(t_lexer *lex, t_stack *st, t_bool backslash)
{
	char *el;

	el = (char *)stack_peek(st);
	if (el && *el == SINGLE_QUOTE)
	{
		if (lex->c == SINGLE_QUOTE)
			stack_pop(st);
		return ;
	}
	if (backslash == TRUE)
		return ;
	identify_expansions(lex, st);
	if (el && *el == DOUBLE_QUOTE && lex->c == DOUBLE_QUOTE)
		stack_pop(st);
	if (el && (*el == SINGLE_QUOTE || *el == DOUBLE_QUOTE))
		return ;
	else if (lex->c == SINGLE_QUOTE || lex->c == DOUBLE_QUOTE )
		stack_push(st, &(lex->c));
}

static void	update_backslash(t_lexer *lex, t_stack *st, t_bool *backslash)
{
	char *last_stack_el;

	last_stack_el = (char *)stack_peek(st);
	if (last_stack_el && *last_stack_el == SINGLE_QUOTE)
		return ;
	*backslash = !(*backslash) && lex->c == BACK_SLASH;
}

static t_bool	is_word_delimeter(t_lexer *lex, t_stack *st, t_bool backslash)
{
	char *last_stack_el;

	last_stack_el = (char *)stack_peek(st);
	if (lexer_is_word(lex->c))
		return (FALSE);
	return (backslash == FALSE && (!last_stack_el || *last_stack_el == '\0'));
}

void		lexer_handle_word(t_lexer *lex)
{
	t_stack			*st;
	t_bool			backslash;

	st = stack_new(sizeof(char), free);
	backslash = FALSE;
	while (lex->c && !is_word_delimeter(lex, st, backslash))
	{
		string_push(lex->word, lex->c);
		update_stack(lex, st, backslash);
		update_backslash(lex, st, &backslash);
		lexer_advance(lex, 1);
	}
	lexer_push_token(lex, WORD);
}
