/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 08:38:12 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/28 16:53:36 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "forty_two_sh.h"
# include "../parse_simple_cmd/parse_simple_cmd.h"
# include "../parse_pipe/parse_pipe.h"

typedef struct	s_parse_and_or
{
	t_logic_sequence	*logic_cmd;
	t_vector			*cmd_tokens;
	t_token				*tokens;
	t_token				current_token;
	size_t				tokens_index;
	size_t				tokens_len;
	t_cmd_type			cmd_type;
}				t_parse_and_or;

void			push_cmd_token(t_parse_and_or *parser);

#endif