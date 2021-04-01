/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forty_two_sh.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:17:07 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/01 10:53:57 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORTY_TWO_SH_H
# define FORTY_TWO_SH_H

# include "libft.h"
# include "typedefs.h"
# include "src/errors/errors.h"

extern int
g_exit_status;
int
g_term_fd;

/*
** ================================ jobs =======================================
*/
void	add_process_to_job(t_job *job, pid_t pid);
t_job	*new_job(t_bool is_background);

/*
** ============================= end jobs ======================================
*/

/*
** ================================ execution ==================================
*/
void	execute_commands(t_vector *commands);
int		execute_simple_cmd(t_simple_command *simple_cmd, t_bool is_background,
			t_bool is_interactive);
int		execute_pipe_seq(t_pipe_sequence *pipe_seq, t_bool is_background,
			t_bool is_interactive);
/*
** ============================= end execution =================================
*/


#endif
