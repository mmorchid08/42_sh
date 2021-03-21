/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:32:57 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/21 11:42:01 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

char	lexer_quote_type(char c)
{
	if (c == DOUBLE_QUOTE || c == SINGLE_QUOTE)
		return (c);
	return (0);
}

int		lexer_is_space(char c, int quote)
{
	return (ft_isspace(c) && !quote);
}

int		lexer_is_number(char c, int quote)
{
	return (ft_isdigit(c) && !quote);
}

int		lexer_is_operator(char c, int quote)
{
	return (!quote && (
		c == ';' || c == '&' || c == '|' || c == '<' || c == '>'));
}

int		is_word(char c, int quote)
{
	return (
		!lexer_is_space(c, quote) &&
		!lexer_is_operator(c, quote));
}
