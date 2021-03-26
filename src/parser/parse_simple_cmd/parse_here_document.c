/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_here_document.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:56:16 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/26 11:06:16 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_bool		is_quote(char c)
{
	return (c == DOUBLE_QUOTE || c == SINGLE_QUOTE || c == BACK_SLASH);
}

static t_bool		str_is_quoted(char *str)
{
	while (*str)
	{
		if (is_quote(*str) > 0)
			return (TRUE);
		++str;
	}
	return (FALSE);
}

static t_delimiter	*get_delimiter(char *str)
{
	t_delimiter	*delim;

	delim = (t_delimiter*)ft_malloc(sizeof(t_delimiter));
	delim->str = str;
	delim->is_quoted = str_is_quoted(delim->str);
	// delim->str = remove_quotes_from_word(delim->str);
	return (delim);
}

static int			read_buffer(char **buffer, char *delimiter)
{
	char	*line;
	int		ret;

	*buffer = ft_strdup("");
	while ((ret = get_next_line(0, &line)) != -1) // != ERROR
	{
		// if (ret == INTERRUPTED)
		// {
		// 	free(*buffer);
		// 	return (EXIT_FAILURE);
		// }
		// if (ret == EXIT)
		// 	break ;
		if (ft_strequ(line, delimiter))
		{
			free(line);
			break ;
		}
		*buffer = ft_strjoin_free(*buffer, line, 1, 1);
		*buffer = ft_strjoin_free(*buffer, "\n", 1, 0);
	}
	// if (ret == ERROR)
	// 	exit(1);
	return (ret == -1 ? EXIT_FAILURE: EXIT_SUCCESS);
}

int			parse_here_doc(char *delimter_str)
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
	if (read_buffer(&buffer, delim->str) == EXIT_FAILURE)
		return (-1);
	// if (!delim->is_quoted)
	// 	buffer = expand_here_doc_buffer(buffer);
	ft_printf(pipe_fds[1], buffer);
	free(buffer);
	close(pipe_fds[1]);
	return (pipe_fds[0]);
}