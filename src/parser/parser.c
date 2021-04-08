/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:28:42 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/08 18:21:29 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_vector	*parser(char *line)
{
	t_vector	*tokens;
	t_vector	*commands;

	(void)line;
	tokens = NULL;
	lexer(&tokens, line);
	lexer_add_newline_token(tokens);
	lexer_print_tokens(tokens);
	commands = parse_complete_commands(tokens);
	print_commands(commands);
	return (NULL);
}
