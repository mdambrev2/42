
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "bircd.h"

void			srv_accept(t_env *e, int s)
{
	int						cs;
	struct sockaddr_in		csin;
	socklen_t			csin_len;
	char					*str;

	csin_len = sizeof(csin);
	cs = X(-1, accept(s, (struct sockaddr*)&csin, &csin_len), "accept");
	printf("New client#%d from %s:%d\n\n", cs,
			inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
	str = client_join_message(e,cs);
	e->fds[cs].name = get_client_name(e, cs); 
	e->fds[cs].chan = strdup("Default Irc");
	write_all_client_with_cs(e, str, strlen(str));
	clean_fd(&e->fds[cs]);
	e->fds[cs].type = FD_CLIENT;
	e->fds[cs].fct_read = client_read;
	e->fds[cs].fct_write = client_write;
}
