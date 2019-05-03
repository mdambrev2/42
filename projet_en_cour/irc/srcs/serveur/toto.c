
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include "bircd.h"

int		circular_buffer(t_env *e, int cs, int r)
{
	char *tmp;
	static int	x = 0;

	tmp = e->fds[cs].buf_read;
	if(tmp[r - 1] == '\n' && x == 0)
	{
		printf("1\n");
		return(r);
	}
	else if(tmp[r - 1] != '\n')
	{
		printf("2\n");

		printf("e->fds[cs].buf_write = %s \n", e->fds[cs].buf_write);
		strcat(e->fds[cs].buf_write, e->fds[cs].buf_read);
		printf("e->fds[cs].buf_write = %s \n", e->fds[cs].buf_write);
		x = 1;
		return(0);
	}
	else if(tmp[r - 1] == '\n' && x == 1)
	{
		strcat(e->fds[cs].buf_write, e->fds[cs].buf_read);
		memcpy(e->fds[cs].buf_read, e->fds[cs].buf_write, BUF_SIZE);
		x = 0;
		memset(e->fds[cs].buf_write, 0, BUF_SIZE);
		return(strlen(e->fds[cs].buf_read));
	}
	return(0);
}	

void	send_to_all_client(t_env *e, int cs, int r)
{
	int i;

	i = 0;
	while (i < e->maxfd)
	{
		if ((e->fds[i].type == FD_CLIENT) &&
				(i != cs))
			send(i, e->fds[cs].buf_read, r, 0);
		i++;
	}
}

void	client_read(t_env *e, int cs)
{
	int	r;

	printf("0\n");
	memset(e->fds[cs].buf_read, 0, BUF_SIZE);
	printf("1\n");
	r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0);	
	if (r <= 0)
	{
		close(cs);
		clean_fd(&e->fds[cs]);
		printf("client #%d gone away\n", cs);
	}
	printf("2\n");
	if((r = circular_buffer(e, cs, r)) != 0)
		send_to_all_client(e, cs, r);
	printf("3\n");
}
