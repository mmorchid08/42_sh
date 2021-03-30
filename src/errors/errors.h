/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:55:34 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/31 17:13:42 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H


typedef enum	t_error 
{
	EACCES = 1,
	ENOTFOUND,
	ENOENT,
	ENOTDIR,
	ENAMETOOLONG,
	ENOHOME,
	ENOOLDPWD,
	EISDIR,
	EREDIRECT,
	EAMBREDIRECT,
	ESYNTAX,
	ETOOMANYPIPES,
	EOPENFILE,
	EUNK
}				t_error;

extern t_error	g_errno;

void			ft_perror(char *prefix, char *suffix, t_bool exit_on_error);
void			ft_strerror(t_error e, char *prefix, char *suffix,
					t_bool exit_on_error);

#endif
