;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/09 16:51:25 by mdambrev          #+#    #+#              ;
;    Updated: 2015/05/09 16:52:09 by mdambrev         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;
; int			ft_toupper(int c);

section .text
	global	_ft_toupper

_ft_toupper:
	mov		rax, rdi
	cmp		rax, 'a'
	jl		.ret
	cmp		rax, 'z'
	jg		.ret
	add		rax, -32

.ret:
	ret
