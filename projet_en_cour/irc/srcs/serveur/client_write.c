
#include <sys/socket.h>
#include "bircd.h"

void	write_all_client(t_env *e, int cs, char *message, int len)
{
	int i;

	i = 0;
	while (i < e->maxfd)
	{
		if ((e->fds[i].type == FD_CLIENT) &&
				(i != cs))
			send(i, message, len, 0);
		i++;
	}
	free(message);
}

void	write_all_client_with_cs(t_env *e, char *message, int len)
{
	int i;

	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT)
			send(i, message, len, 0);
		i++;
	}
	free(message);
}

void	write_all_client_in_chan(t_env *e,int cs , char *message, int len)
{
	int i;

	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT 
				&& (i != cs) 
				&& strcmp(e->fds[i].chan, e->fds[cs].chan) == 0)
			send(i, message, len, 0);
		i++;
	}
	free(message);
}

void	write_all_client_in_chan_with_cs(t_env *e,int cs , char *message, int len)
{
	int i;

	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT 
				&& strcmp(e->fds[i].chan, e->fds[cs].chan) == 0)
			send(i, message, len, 0);
		i++;
	}
	free(message);
}

void	client_write(t_env *e, int cs)
{
	e++;
	e--;
	cs++;
	cs--;
}
