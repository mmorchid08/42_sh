/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:11:49 by hmzah             #+#    #+#             */
/*   Updated: 2021/04/16 17:16:35 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int		check_file(char *path)
{
	if (access(path, F_OK) != -1)
		return (1);
	return (0);
}

char	*ft_search_env(char *key)
{
	t_var	*env;
	int		i;

	env = (t_var *)g_shell_env->array;
	i = 0;
	while (i < (int)g_shell_env->length)
	{
		if (!(ft_strcmp(env[i].key, key)))
			return (env[i].value);
		i++;
	}
	return (NULL);
}

char	*get_full_path(char *cmd)
{
	char	*full_path;

	if (!(check_file(cmd) && cmd[0] != '.' && cmd[0] != '/'))
		full_path = try_every_possibility(cmd, ft_search_env("PATH"));
	else
		full_path = ft_strdup(cmd);
	return (full_path);
}