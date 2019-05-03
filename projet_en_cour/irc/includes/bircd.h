#ifndef BIRCD_H_
# define BIRCD_H_

# include <sys/select.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/socket.h>
# include "bircd.h"
# include <string.h>
# include <stdlib.h>
# include <math.h>

# define FD_FREE	0
# define FD_SERV	1
# define FD_CLIENT	2

# define BUF_SIZE	4096

# define Xv(err,res,str)	(x_void(err,res,str,__FILE__,__LINE__))
# define X(err,res,str)		(x_int(err,res,str,__FILE__,__LINE__))
# define MAX(a,b)	((a > b) ? a : b)

# define USAGE		"Usage: %s port\n"

typedef struct	s_fd
{
  int	type;
  void	(*fct_read)();
  void	(*fct_write)();
  char	buf_read[BUF_SIZE + 1];
  char	buf_write[BUF_SIZE + 1];
  char  buf[BUF_SIZE + 1];
  char	*name;
  char	*chan;
}		t_fd;

typedef struct	s_env
{
  t_fd		*fds;
  int		port;
  int		maxfd;
  int		max;
  int		r;
  fd_set	fd_read;
  fd_set	fd_write;
}		t_env;

char	*ft_itoa(int n);
void    write_all_client_with_cs(t_env *e, char *message, int len);
char	*ft_strjoin(char const *s1, char const *s2);
int     nick_cmd(t_env *e, int cs, char **tab);
char	**ft_strsplit(char const *s, char c);
int		go_cmd(t_env *e, int cs);
char	*get_client_name(t_env *env, int cs);
char	*client_leave_message(t_env *env, int cs);
char	*client_join_message(t_env *env, int cs);
void	init_env(t_env *e);
void    write_all_client(t_env *e, int cs, char *message, int len);
void	get_opt(t_env *e, int ac, char **av);
void	main_loop(t_env *e);
void	srv_create(t_env *e, int port);
void	srv_accept(t_env *e, int s);
void	client_read(t_env *e, int cs);
void	client_write(t_env *e, int cs);
void	clean_fd(t_fd *fd);
int	x_int(int err, int res, char *str, char *file, int line);
void	*x_void(void *err, void *res, char *str, char *file, int line);
void	init_fd(t_env *e);
void	do_select(t_env *e);
void	check_fd(t_env *e);
void	send_message(t_env *e, int cs, char **tab);
void	cmd_who(t_env *e, int cs);
void	cmd_join(t_env *e, int cs, char **tab);
void	write_all_client_in_chan(t_env *e,int cs ,char *message, int len);
void	write_all_client_in_chan_with_cs(t_env *e, int cs, char *message, int len);
void    cmd_leave(t_env *e, int cs, char **tab);

#endif /* !BIRCD_H_ */
