/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:39:18 by mdambrev          #+#    #+#             */
/*   Updated: 2019/10/01 13:33:51 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int		print_illegal_option(char **argv, int i)
{
	ft_printf("\nIllegal Option : %s \n\nUsage :\n\n", argv[i]);
	ft_printf("-p, echo STDIN to STDOUT and append the checksum to STDOUT\n");
	ft_printf("-q, quiet mode\n");
	ft_printf("-r, reverse the format of the output.\n");
	ft_printf("-s, print the sum of the given string\n\n");
	return(1);
}

int		print_args_error(void)
{
	ft_printf("\nError ft_ssl : missing Argument\n");
	ft_printf("Usage : ./ft_ssl [-pqrs] Arguments\n\n");
	return(1);
}

int		print_digest_error(void)
{
	ft_printf("ft_ssl Error : Invalide or missing digest commands\n");
	ft_printf("Usage : ./ft_ssl [md5 sha256] [-pqrs] Arguments\n\n");
	return(1);
}



int		print_string_error(void)
{
	ft_printf("\nError ft_ssl : option -s, arguments needed\n");
	ft_printf("Usage : ./ft_ssl [md5 sha256] [ . . . -s] Arguments\n\n");
	return(1);
}

int		print_stdin_error(void)
{
	ft_printf("Error ft_ssl : STDIN missing\n");
	ft_printf("Usage : echo \"string\" |");
	ft_printf(" ./ft_ssl [md5 sha256] [-p . . .] Arguments\n\n");
	return(1);
}
