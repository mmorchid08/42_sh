/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:53:54 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/24 10:38:40 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "forty_two_sh.h"

extern char	*g_tokens_to_string[];

t_vector	*lexer(char *line, t_bool enable_alias_subtitution);
void		lexer_print_tokens(t_vector *tokens_vec);
void		lexer_add_newline_token(t_vector *tokens);

#endif
