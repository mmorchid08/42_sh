/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:39:53 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/24 19:02:56 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "forty_two_sh.h"

typedef struct	s_parser
{
	t_vector	*commads;
	t_vector	*cmd_tokens;
	t_token		*tokens;
	t_token		current_token;
	size_t		tokens_index;
	size_t		tokens_len;
	t_cmd_type	cmd_type;
}				t_parser;

#endif
