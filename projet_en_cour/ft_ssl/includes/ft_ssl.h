/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:36:51 by mdambrev          #+#    #+#             */
/*   Updated: 2019/10/02 14:52:16 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>  
# include <stdio.h>
# include <libft.h>
# include <ft_printf.h>
# define BUF_SIZE 4096
typedef struct	s_env
{
	int			echo;
	int			quiet;
	int			reverse;
	int			string;
	int			sha;
	int			md;
	int			args;
	char		*message;
}				t_env;

typedef struct			s_mess
{
	char				*message;	
	int					len;
	unsigned	char	*data;
	int					data_len;
	int					i;
	uint32_t			h[8];
	uint32_t			a;
	uint32_t			b;
	uint32_t			c;
	uint32_t			d;
	uint32_t			e;
	uint32_t			f;
	uint32_t            g;
	uint32_t            *w;
	uint32_t            tmp;
	uint32_t				cons[64];
	uint32_t				hexa[64];

}						t_mess;

char	*get_md5(char *message, t_env *env);
void	get_sha(char *message);
void	set_const_tab(t_mess *infos);
void	set_hexa_tab(t_mess *infos);
int		parsing_argv(int argc, char **argv, t_env *env);
int		print_illegal_option(char **argv, int i);
int		print_args_error(void);
int     print_string_error(void);
int     print_digest_error(void);
int     print_stdin_error(void);
int     check_string(char **argv, t_env *env);
int	    check_stdin(int argc, char **argv, t_env *env);
int     check_file(char **argv, t_env *env);
void	set_hexa_tab_sha(t_mess *infos);
void	set_const_tab_sha(t_mess *infos);

#endif
