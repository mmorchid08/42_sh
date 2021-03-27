/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:26:41 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/27 12:47:04 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "forty_two_sh.h"

typedef struct	s_parse_commplete
{
	t_vector	*commands;
	t_vector	*cmd_tokens;
	t_token		*tokens;
	t_token		current_token;
	size_t		tokens_index;
	size_t		tokens_len;
	t_cmd_type	cmd_type;
}				t_parse_commplete;

#endif
