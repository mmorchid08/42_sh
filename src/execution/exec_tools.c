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

char			*env_get(t_vector *env, char *key)
{
	t_var	*vars;
	size_t	i;

	i = 0;
	vars = env->array;
	while (i < env->length)
	{
		if (ft_strequ(key, vars[i].key))
			return (vars[i].value);
		++i;
	}
	return (NULL);
}

char	*try_every_possibility(char *cmd, char *path_env)
{
	char	**ab;
	char	*tmp;
	char	*tmp2;
	int		i;

	if (!path_env || !(ab = ft_strsplit(path_env, ':')))
		return (ft_strdup(cmd));
	i = -1;
	tmp = NULL;
	tmp2 = NULL;
	while (ab[++i])
	{
		tmp = ft_strjoin(ab[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (check_file(tmp2))
		{
			ft_free_strings_array(ab);
			return (tmp2);
		}
		free(tmp2);
	}
	ft_free_strings_array(ab);
	return (ft_strdup(cmd));
}

char	*get_full_path(char *cmd)
{
	char	*full_path;

	if (!(check_file(cmd) && cmd[0] != '.' && cmd[0] != '/'))
		full_path = try_every_possibility(cmd, env_get(g_shell_env, "PATH"));
	else
		full_path = ft_strdup(cmd);
	return (full_path);
}
