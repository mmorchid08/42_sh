/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:55:34 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/15 16:03:30 by hmzah            ###   ########.fr       */
=======
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:55:34 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/22 09:23:04 by ylagtab          ###   ########.fr       */
>>>>>>> origin/expansion
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum	e_error
{
	EACCES = 1,
	ENOCMD,
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
	EFORK,
<<<<<<< HEAD
	EOPENFILE,
	ENOJOB,
=======
>>>>>>> origin/expansion
	EUNK
}				t_error;

extern t_error	g_errno;

void			ft_perror(char *prefix, char *suffix, t_bool exit_on_error);
void			ft_strerror(t_error e, char *prefix, char *suffix,
					t_bool exit_on_error);

#endif
