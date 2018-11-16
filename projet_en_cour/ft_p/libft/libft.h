/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 23:03:39 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/16 05:50:04 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "lib_list.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "get_next_line.h"

#define INIT 2
#define	DATA 3
#define DONE 4
#define RECV 1
#define READ 2

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct	s_message 
{
	int			messagetype;
	int			mode;
	int			len;
}				t_message;

int					static_error(int x);
int					send_all(int cs, char *str, int cpt);
char				*recv_instruction(int sock);
int					read_instruction(int sock);
int					send_string(int cs, char *str);
char				*recv_string(int cs);
int					get_fork(char *cmd);
char				*read_data(int cs, t_message msg);
char                *read_data2(int cs, t_message msg);
int					receive(int cs, t_message *msg);
int	                init_connection(int cs);
int					send_data(int cs, void *buf, int len);
int					done_connection(int cs);
char				*if_exist_in_tab(char **tab, char *str);
int					secure_folder(char *racine, char *str, char *occu, int *x);
int					secure_cmd(char *cmd, char *racine_serv);
char				*get_absolute_path_ls(const char *path, char **pwd);
char				*get_str_end(char *str);
char				*get_occu_by_delim(char *str, char delim, int n_occu);
int					ft_cd(const char *path, int sec, char *racine_serv);
char				*ft_strcut(const char *s1, const char *s2);
int                 put_fd_in_files(int fd, char *path_file);
uint64_t			swap_uint64(uint64_t n);
uint32_t			swap_uint32(uint32_t val);
char				*ft_strend(char *str);
void				ft_put_hexa(uintmax_t quotient);
void				ft_put_base_max(uintmax_t quotient, int base);
int					ft_putwchar(wchar_t c, int aff);
int					ft_putwstr(wchar_t *wstr, int aff);
int					ft_wstrlen(wchar_t *wstr);
wchar_t				*ft_wstrdup(wchar_t *s);
wchar_t				*ft_wstrjoin(wchar_t *s1, wchar_t *s2);
wchar_t				*ft_wstrndup(wchar_t *str, int start, int end);
wchar_t				*ft_wstrnew(size_t size);
wchar_t				*ft_wstrsub(wchar_t *s, unsigned int start, size_t len);
int					ft_weight_wstrchar(wchar_t *s);
int					ft_weight_char(wchar_t s);
int					ft_charchr(char *str, char c);
char				*ft_strlower(char *str);
char				*ft_strupper(char *str);
char				*ft_convert_base_max(uintmax_t quotient, int base);
char				*ft_convertn_base_max(uintmax_t quotient, int base, int n);
char				*base_alloc(uintmax_t quotient, uintmax_t *mult, int base);
char				*ft_strndup(char *str, int start, int end);
int					ft_stringtonbr(char *str);
int					nb_char_str(char *str, char c);
void				replace_n_char(char **str, char ent, char sort, int n);
void				replace_char(char **str, char ent, char sort);
int					nb_word_str(char *str, char c);
void				ft_putchar(char c);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list				*ft_lstnew(void const *content, size_t	content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
char				*ft_itoa(int n);
char				*ft_itoa_max(void *z);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_strclr(char *s);
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
char				*ft_strnew_bin(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset (void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isprint(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isascii(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_nbrlen(int x);
char				*dup_occu_by_delim(char *str, char delim, int n_occu);

#endif
