/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:39:53 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/26 15:32:27 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "forty_two_sh.h"
# include "lexer/lexer.h"
# include "parse_simple_cmd/parse_simple_cmd.h"
# include "parse_pipe/parse_pipe.h"
# include "parse_and_or/parse_and_or.h"

typedef struct	s_parser
{
	t_vector	*commands;
	t_vector	*cmd_tokens;
	t_token		*tokens;
	t_token		current_token;
	size_t		tokens_index;
	size_t		tokens_len;
	t_cmd_type	cmd_type;
}				t_parser;

t_vector	*parser(t_vector *tokens);

#endif
