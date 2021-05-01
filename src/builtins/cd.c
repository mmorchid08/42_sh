/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:17:12 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/01 10:41:23 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"
#include <dirent.h>

void	ft_update_pwd(char *path)
{
	char	*pwd;

	pwd = env_get(g_shell_env, "PWD");
	if (pwd)
		env_set_value(g_shell_env, "OLDPWD", pwd);
	env_set_value(g_shell_env, "PWD", path);
}

int	get_cd_flag(char ***cmd)
{
	char	**tmp;
	int		ret;
	int		i;

	ret = 1;
	tmp = *cmd;
	while (*tmp)
	{
		if (ft_strequ(*tmp, "-") || **tmp != '-')
			break ;
		i = 0;
		while (tmp[0][++i])
		{
			if (tmp[0][i] != 'L' && tmp[0][i] != 'P')
				return (ft_printf(2, "cd", "usage: cd [-L|-P] [dir]\n"));
			ret = tmp[0][i] == 'L';
		}
		tmp++;
	}
	*cmd = tmp;
	return (ret);
}

char	*ft_get_cwd(char *path, char *ret, char *tmp, char *tmp2)
{
	int			diff;

	if (ret && !(*ret = 0))
		while (*path)
			if ((tmp = ft_skip_unitl_char(path, "/", NULL)))
			{
				if ((diff = (tmp - path)) == 2 && ft_strnequ(path, "..", 2))
				{
					if (*ret && (tmp2 = ft_strrchr(ret, '/')))
						*tmp2 = 0;
				}
				else if (diff && (diff != 1 || *path != '.'))
				{
					if ((tmp2 = ft_strchr(ret, 0)) && (!*ret || tmp2[-1] != 47))
						ft_strcat(tmp2, "/");
					ft_strncat(tmp2 + 1, path, diff);
				}
				path += diff + !!*tmp;
			}
	return (ret && !*ret ? ft_strcat(ret, "/") : ret);
}

char	*get_cd_path(char *path)
{
	char	*pwd;
	char	*tmp;

	if (!path)
		path = env_get(g_shell_env, "HOME");
	else if (ft_strequ(path, "-"))
	{
		path = env_get(g_shell_env, "OLDPWD");
	}
	if (path && *path && !ft_isinstr(*path, "./"))
		path = concat_path_with_cdpath(path);
	if (path && *path && *path != '/' && (pwd = env_get(g_shell_env, "PWD")))
	{
		tmp = path;
		path = ft_strnjoin((char *[]){pwd, "/", path}, 3);
	}
	return (path);
}

int	ft_cd(char **cmd)
{
	char	*path;
	int		logicaly;
	DIR		*dir;

	if ((logicaly = get_cd_flag(&cmd)) == -1 || (cmd[0] && cmd[1]))
		return (cmd[1] ? ft_printf(2, "cd: to many argument\n") : -1);
	path = get_cd_path(ft_strdup(*cmd));
	if (path)
	{
		if (logicaly)
			path = ft_get_cwd(path, ft_strdup(path), NULL, NULL);
		if (!chdir(path))
		{
			if (!logicaly)
				path = getcwd(NULL, 0);
			ft_update_pwd(path);
			return (0);
		}
		dir = opendir(path);
		if (dir != NULL)
			ft_printf(2, "cd: permission denied\n");
		else
			ft_printf(2, "cd: directory not found\n");
		return (15);
	}
	return (1);
}
