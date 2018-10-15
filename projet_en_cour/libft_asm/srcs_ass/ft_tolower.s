# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tolower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/09 17:03:06 by mdambrev          #+#    #+#              #
#    Updated: 2015/05/09 17:03:13 by mdambrev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; int			ft_tolower(int c);

section .text
	global	_ft_tolower

_ft_tolower:
	mov		rax, rdi
	cmp		rax, 'A'
	jl		.ret
	cmp		rax, 'Z'
	jg		.ret
	add		rax, 32
.ret:
	ret
