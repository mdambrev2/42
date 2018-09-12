/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:44:51 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:25:48 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# define BLOCK_NUMBER	107
# define COEFF_TINY		5
# define COEFF_SMALL	29
# define DATA_STRUCT	sizeof(t_chained)
# define DATA_RACINE	sizeof(t_addrzone)
# include <unistd.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include <sys/mman.h>
# include <sys/types.h>
# include <stdlib.h>
# include <pthread.h>

typedef	struct				s_addrzone
{
	long long int			start;
	long long int			end;
	long long int			size;
	long long int			data;
	struct s_addrzone		*racine;
	struct s_chained		*next;
	struct s_chained		*prev;
	struct s_addrzone		*zone_next;
	struct s_addrzone		*zone_prev;
	uintmax_t				nb_malloc;
}							t_addrzone;

typedef	struct				s_zone
{
	size_t					t_block_size;
	size_t					s_block_size;
	size_t					l_block_size;
	int						t_zone_size;
	int						s_zone_size;
	int						l_zone_size;
	int						type;
	int						nt_zone;
	int						ns_zone;
	int						nl_zone;
	t_addrzone				*t_zone;
	t_addrzone				*s_zone;
	t_addrzone				*l_zone;
}							t_zone;

typedef	struct				s_chained
{
	long long int			start;
	long long int			end;
	long long int			data;
	int						free;
	size_t					size;
	struct s_chained		*next;
	struct s_chained		*prev;
	struct s_addrzone		*racine;
}							t_chained;

pthread_mutex_t				g_malloc_lock;
t_zone						g_zone;

t_addrzone					*ft_set_map(int x);
extern	void				*malloc(size_t size);
extern	void				*reallocf(void *ptr, size_t size);
void						ft_init_map(void);
void						ft_set_block_size(size_t size);
t_addrzone					*ft_create_malloc_list(void *ptr);
t_chained					*ft_add_malloc_list(t_addrzone *racine, void *ptr);
t_addrzone					*ft_add_zone_list(t_addrzone *racine, void *ptr);
void						*ft_set_data(size_t size);
void						ft_set_new_zone(void);
void						*ft_check_data(size_t size);
extern	void				show_alloc_mem(void);
extern	void				free(void *ptr);
void						*ft_check_tiny(void *ptr);
void						*ft_check_small(void *ptr);
void						*ft_check_large(void *ptr);
void						ft_delete_tiny_ptr(void *ptr);
void						ft_delete_small_ptr(void *ptr);
void						ft_delete_large_ptr(void *ptr);
void						ft_delete_elem(t_addrzone *racine, void *ptr);
extern	void				*realloc(void *ptr, size_t size);
void						*ft_check_realloc(void *ptr);
void						*ft_check_block(size_t size, void *ptr);
extern	void				*calloc(size_t nmemb, size_t size);
t_addrzone					*ft_reset_malloc_zone(void *ptr);
void						*ft_check_allocate_memorie(size_t size);
int							put_address(t_chained *tmp2, t_addrzone *tmp1
														, int *total);
int							put_page(t_chained *tmp2, t_addrzone *tmp1
													, int *total);

#endif
