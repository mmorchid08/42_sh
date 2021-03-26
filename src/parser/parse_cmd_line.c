/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:28:42 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/26 14:48:56 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_vector	*parse_cmd_line(char *line)
{
	t_vector *tokens;

	(void)line;
	tokens = lexer(line, TRUE);
	lexer_add_newline_token(tokens);
	lexer_print_tokens(tokens);
	(void)parser(tokens);
	// vector_free(tokens);

	return (NULL);
}
