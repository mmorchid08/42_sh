/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:28:42 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/28 16:51:45 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_vector	*parser(char *line)
{
	t_vector *tokens;

	(void)line;
	tokens = lexer(line, TRUE);
	lexer_add_newline_token(tokens);
	lexer_print_tokens(tokens);
	(void)parse_complete_commands(tokens);
	// vector_free(tokens);

	return (NULL);
}
