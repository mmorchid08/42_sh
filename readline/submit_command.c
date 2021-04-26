/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submit_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 23:08:39 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/04 17:30:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_internal.h"

char		*submit_command(void)
{
	goto_end();
	ft_putchar('\n');
	return (dynstr_vec_to_str(g_rl_state.lines));
}
