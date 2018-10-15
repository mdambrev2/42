/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_asm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 11:42:54 by mdambrev          #+#    #+#             */
/*   Updated: 2015/05/16 21:42:22 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ASM_H
# define LIBFT_ASM_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

int		ft_toupper(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_isascii(int c);
int		ft_isalnum(int c);
int		ft_islower(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isupper(int c);
int		ft_strlen(char *str);
char	*ft_strdup(const char *s1);
int		ft_puts(char *s);
char	*ft_strcat(char *dest, const char *str2);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_cat(int fd);
char	*ft_strnew(size_t size);
void	ft_strclr(char *str);
void	*ft_memalloc(size_t size);
void	ft_putchar(char c);

#endif
