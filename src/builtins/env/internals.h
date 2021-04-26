/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:26:11 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/02 18:37:21 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "forty_two_sh.h"

void	env_set(t_vector *env, char *key, char *value);
void	env_unset(t_vector *env, char *key);
void	env_set_is_exported(t_vector *env, char *key, t_bool is_exported);

#endif
