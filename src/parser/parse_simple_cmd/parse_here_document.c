/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_here_document.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:56:16 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/22 15:38:30 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_bool	str_is_quoted(char *str)
{
	while (*str)
	{
		if (*str == DOUBLE_QUOTE || *str == SINGLE_QUOTE || *str == BACK_SLASH)
			return (TRUE);
		++str;
	}
	return (FALSE);
}

// delim->str = remove_quotes_from_word(delim->str);

static t_delimiter	*get_delimiter(char *str)
{
	t_delimiter	*delim;

	delim = (t_delimiter *)ft_malloc(sizeof(t_delimiter));
	delim->str = str;
	delim->is_quoted = str_is_quoted(delim->str);
	return (delim);
}

static int	read_buffer(char **buffer, char *delimiter)
{
	char	*line;
	int		ret;

	*buffer = ft_strdup("");
	while (1)
	{
		ret = readline_21sh(&line, ">");
		if (ret == ERROR)
			exit(1);
		if (ret == INTERRUPTED)
		{
			free(*buffer);
			return (EXIT_FAILURE);
		}
		if (ret == EXIT)
			break ;
		if (ft_strequ(line, delimiter))
		{
			free(line);
			break ;
		}
		*buffer = ft_strjoin_free(*buffer, line, 1, 1);
		*buffer = ft_strjoin_free(*buffer, "\n", 1, 0);
	}
	return (ret);
}

// if (!delim->is_quoted)
// 	buffer = expand_here_doc_buffer(buffer);

int	parse_here_doc(char *delimter_str)
{
	t_delimiter	*delim;
	char		*buffer;
	int			pipe_fds[2];

	if (pipe(pipe_fds) == -1)
	{
		ft_strerror(EREDIRECT, NULL, NULL, FALSE);
		return (-1);
	}
	delim = get_delimiter(delimter_str);
	if (read_buffer(&buffer, delim->str) == -1)
		return (-1);
	free(delim);
	ft_putstr_fd(buffer, pipe_fds[1]);
	free(buffer);
	close(pipe_fds[1]);
	return (pipe_fds[0]);
}
