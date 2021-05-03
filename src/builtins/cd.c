/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:17:12 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/03 15:37:56 by hmzah            ###   ########.fr       */
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
	int			df;

	if (ret && !assign_p(ret, 0))
	{
		while (*path)
		{
			if (assign_p(&tmp, ft_skip_unitl_char(path, "/", NULL)))
			{
				if (assign_i(&df, tmp - path) == 2 && ft_strnequ(path, "..", 2))
				{
					if (*ret && assign_p(&tmp2, ft_strrchr(ret, '/')))
						*tmp2 = 0;
				}
				else if (df && (df != 1 || *path != '.'))
				{
					if (assign_p(&tmp2, ft_strchr(ret, 0))
						&& (!*ret || tmp2[-1] != 47))
						ft_strcat(tmp2, "/");
					ft_strncat(tmp2 + 1, path, df);
				}
				path += df + !!*tmp;
			}
		}
	}
	return (ter_p(ret && !*ret, ft_strcat(ret, "/"), ret));
}

char	*get_cd_path(char *ret)
{
	char	*pwd;
	char	*tmp;
	char	*path;

	path = ft_strdup(ret);
	if (!path)
		path = env_get(g_shell_env, "HOME");
	else if (ft_strequ(path, "-"))
	{
		path = env_get(g_shell_env, "OLDPWD");
	}
	if (path && *path && !ft_isinstr(*path, "./"))
		path = concat_path_with_cdpath(path);
	if (path && *path && *path != '/'
		&& assign_p(&pwd, env_get(g_shell_env, "PWD")))
	{
		tmp = path;
		path = ft_strnjoin((char *[]){pwd, "/", path}, 3);
	}
	return (path);
}

int	ft_cd(char **cmd)
{
	char	*pth;
	int		logicaly;
	DIR		*dir;
	char	*tmp;

	if (assign_i(&logicaly, get_cd_flag(&cmd)) == -1 || (cmd[0] && cmd[1]))
		return (ter_i(!!cmd[1], ft_printf(2, "cd: to many argument\n"), -1));
	pth = get_cd_path(*cmd);
	if (pth)
	{
		if (logicaly)
		{
			tmp = ft_strdup(pth);
			pth = ft_get_cwd(pth, tmp, NULL, NULL);
			free(tmp);
		}
		if (!chdir(pth))
		{
			if (!logicaly)
				pth = getcwd(NULL, 0);
			ft_update_pwd(pth);
			return (0);
		}
		dir = opendir(pth);
		if (dir != NULL)
			return (ft_printf(2, "cd: permission denied\n") * 0 + 15);
		return (ft_printf(2, "cd: directory not found\n") * 0 + 15);
	}
	return (1);
}
