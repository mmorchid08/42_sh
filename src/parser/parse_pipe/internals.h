/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:57:01 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/30 19:33:56 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "forty_two_sh.h"
# include "../parse_simple_cmd/parse_simple_cmd.h"

typedef struct	s_parse_pipe
{
	t_pipe_sequence	*pipe_cmd;
	t_vector		*cmd_tokens;
	t_token			*tokens;
	t_token			current_token;
	size_t			tokens_index;
	size_t			tokens_len;
}				t_parse_pipe;

#endif