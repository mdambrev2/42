
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "bircd.h"
#include <string.h>
#include <stdlib.h>

int     circular_buffer(t_env *e, int cs, int r)
{
	char *tmp;
	static int  x = 0;

	tmp = e->fds[cs].buf_read;
	if(tmp[r - 1] == '\n' && x == 0)
		return(r);
	else if(tmp[r - 1] != '\n')
	{
		strcat(e->fds[cs].buf, e->fds[cs].buf_read);
		x = 1;
		return(0);
	}
	else if(tmp[r - 1] == '\n' && x == 1)
	{
		strcat(e->fds[cs].buf, e->fds[cs].buf_read);
		memcpy(e->fds[cs].buf_read, e->fds[cs].buf, BUF_SIZE);
		memset(e->fds[cs].buf, 0, BUF_SIZE);	
		x = 0;
		return(strlen(e->fds[cs].buf_read));
	}
	return(0);
}

int		add_name(t_env *e, int cs)
{
	char *str;
	int ret;
	char tmp[BUF_SIZE];

	memset(tmp, 0, BUF_SIZE);
	memcpy(tmp, e->fds[cs].buf_read, BUF_SIZE);
	memset(e->fds[cs].buf_read, 0, BUF_SIZE);
	str = get_client_name(e, cs);
	strcat(e->fds[cs].buf_read, str);
	strcat(e->fds[cs].buf_read, ": ");
	strcat(e->fds[cs].buf_read, tmp);
	ret = strlen(str);
	free(str);
	return(ret + 2);
	
}

void	rase_infos(t_env *e, int cs)
{
	memset(e->fds[cs].buf_read, 0, BUF_SIZE);
	memset(e->fds[cs].buf_write, 0, BUF_SIZE);
	free(e->fds[cs].name);
	e->fds[cs].name = NULL;
}

void	client_read(t_env *e, int cs)
{
	int	r;
	char *str;

	memset(e->fds[cs].buf_read, 0, BUF_SIZE);
	r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0);
	if (r <= 0)
	{
		rase_infos(e, cs);
		str = client_leave_message(e, cs);
		printf("%s\n", str);
		write_all_client(e, cs, str, strlen(str));
		close(cs);
		clean_fd(&e->fds[cs]);
	}
	else
	{
		if((r = circular_buffer(e, cs, r)) == 0)
			return;
		if(e->fds[cs].buf_read[0] != '/')
		{
			r +=  add_name(e, cs);
			write_all_client_in_chan(e, cs, strdup(e->fds[cs].buf_read), r);
		}
		else
			go_cmd(e, cs);
	}
}
