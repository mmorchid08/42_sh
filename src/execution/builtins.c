/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:11:49 by hmzah             #+#    #+#             */
/*   Updated: 2021/04/30 08:04:39 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	check_builtins(char *cmd)
{
	if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "set")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "exit")
		|| !ft_strcmp(cmd, "hash") || !ft_strcmp(cmd, "test")
		|| !ft_strcmp(cmd, "type") || !ft_strcmp(cmd, "jobs")
		|| !ft_strcmp(cmd, "alias") || !ft_strcmp(cmd, "fg")
		|| !ft_strcmp(cmd, "bg"))
		return (1);
	return (0);
}

void	execute_builtins(char **cmd, t_vector *red)
{
	if (!ft_strcmp(cmd[0], "test"))
		g_exit_status = ft_test(cmd);
	else if (!ft_strcmp(cmd[0], "env"))
		env_print(g_shell_env, TRUE);
	else if (!ft_strcmp(cmd[0], "echo"))
		g_exit_status = ft_echo(cmd, red);
	else if (!ft_strcmp(cmd[0], "jobs"))
		g_exit_status = ft_jobs(cmd);
	else if (!ft_strcmp(cmd[0], "cd"))
		;// ft_cd(cmd);
	else if (!ft_strcmp(cmd[0], "hash"))
		;// ft_hash(cmd);
	else if (!ft_strcmp(cmd[0], "fg"))
		g_exit_status = ft_fg(cmd);
	else if (!ft_strcmp(cmd[0], "bg"))
		g_exit_status = ft_bg(cmd);
	else if (!ft_strcmp(cmd[0], "set"))
		;// ft_set(cmd);
	else if (!ft_strcmp(cmd[0], "unset"))
		;// ft_unset(cmd);
	else if (!ft_strcmp(cmd[0], "export"))
		g_exit_status = export(cmd);
	else if (!ft_strcmp(cmd[0], "type"))
		;// ft_type(cmd);
	else if (!ft_strcmp(cmd[0], "alias"))
		;// ft_alias(cmd);
	else if (!ft_strcmp(cmd[0], "unalias"))
		;// ft_unalias(cmd);
}
