/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 11:45:15 by mdambrev          #+#    #+#             */
/*   Updated: 2015/06/13 08:53:41 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_asm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>

void        launch_isalnum(int c)
{
	int x;

	x = 0;

	if (ft_isalnum(c) != isalnum(c))
		printf("\033[31mERROR : '%d'\033[00m\n", c);
	if(c == 127)
		printf("\033[32mOK\033[00m\n");

}

void        launch_isupper(int c)
{
	int x;

	x = 0;

	if (ft_isupper(c) != isupper(c))
		printf("\033[31mERROR : '%d'\033[00m\n", c);
	if(c == 127)
		printf("\033[32mOK\033[00m\n");

}


void        launch_islower(int c)
{
	int x;

	x = 0;

	if (ft_islower(c) != islower(c))
		printf("\033[31mERROR : '%d'\033[00m\n", c);
	if(c == 127)
		printf("\033[32mOK\033[00m\n");

}


void        launch_isprint(int c)
{
	int x;

	x = 0;

	if (ft_isprint(c) != isprint(c))
		printf("\033[31mERROR : '%d'\033[00m\n", c);
	if(c == 127)
		printf("\033[32mOK\033[00m\n");

}

void        launch_isdigit(int c)
{
	int x;

	x = 0;

	if (ft_isdigit(c) != isdigit(c))
		printf("\033[31mERROR : '%d'\033[00m\n", c);
	if(c == 127)
		printf("\033[32mOK\033[00m\n");

}

void        launch_isascii(int c)
{
	int x;

	x = 0;

	if (ft_isascii(c) != isascii(c))
		printf("\033[31mERROR : '%d'\033[00m\n", c);
	if(c == 127)
		printf("\033[32mOK\033[00m\n");

}

void        launch_isalpha(int c)
{
	int x;

	x = 0;

	if (ft_isalpha(c) != isalpha(c))
		printf("\033[31mERROR : '%d'\033[00m\n", c);
	if(c == 127)
		printf("\033[32mOK\033[00m\n");

}

void        launch_toupper(int c)
{
	int x;

	x = 0;

	if (ft_toupper(c) != toupper(c))
		printf("\033[31mERROR : '%d'\033[00m\n", c);
	if(c == 127)
		printf("\033[32mOK\033[00m\n");

}

void        launch_tolower(int c)
{
	int x;

	x = 0;

	if (ft_tolower(c) != tolower(c))
		printf("\033[31mERROR : '%d'\033[00m\n", c);
	if(c == 127)
		printf("\033[32mOK\033[00m\n");

}

void    test_is()
{
	int        nb;

	nb = -127;
	printf("\n\033[33m------- Test FT_TOUPPER -------\033[00m\n");
	while(nb++ <= 127)
		launch_toupper(nb);
	nb = -127;
	printf("\n\033[33m------- Test FT_ISPRINT -------\033[00m\n");
	while(nb++ <= 127)
		launch_isprint(nb);
	nb = -127;
	printf("\n\033[33m------- Test FT_TOLOWER -------\033[00m\n");
	while(nb++ <= 127)
		launch_tolower(nb);
	nb = -127;
	printf("\n\033[33m------- Test FT_ISASCII -------\033[00m\n");
	while(nb++ <= 127)
		launch_isascii(nb);
	nb = -127;
	printf("\n\033[33m------- Test FT_ISALNUM -------\033[00m\n");
	while(nb++ <= 127)
		launch_isalnum(nb);
	nb = -127;
	printf("\n\033[33m------- Test FT_ISDIGIT -------\033[00m\n");
	while(nb++ <= 127)
		launch_isdigit(nb);
	nb = -127;
	printf("\n\033[33m------- Test FT_ISALPHA -------\033[00m\n");
	while(nb++ <= 127)
		launch_isalpha(nb);
	nb = -127;
	printf("\n\033[33m------- Test FT_ISUPPER -------\033[00m\n");
	while(nb++ <= 127)
		launch_isupper(nb);
	nb = -127;
	printf("\n\033[33m------- Test FT_ISLOWER -------\033[00m\n");
	while(nb++ <= 127)
		launch_islower(nb);
}

void test_strcat()
{
	char	buf[30];

	bzero(buf, 30);
	ft_strcat(buf, "");
	ft_strcat(buf, "je");
	ft_strcat(buf, " suis ");
	ft_strcat(buf, "u");
	ft_strcat(buf, "n ");
	ft_strcat(buf, "");
	ft_strcat(buf, "dieu");
	printf("\n\033[33m------- Test FT_STRCAT -------\033[00m\n");
	if(strcmp(buf, "je suis un dieu") == 0)
		printf("\033[32mOK\033[00m\n");	
	else
		printf("\033[31mERROR :\033[00m\n");
}

void test_bzero()
{
	char str1[] = "12345678";
	char str2[] = "12345678";
	
	ft_bzero(str1, 6);
	bzero(str2, 6);
	printf("\n\033[33m------- Test FT_BZERO -------\033[00m\n");
	if(memcmp(str1, str2, 8) == 0)
		printf("\033[32mOK\033[00m\n");
	else
		printf("\033[31mERROR\033[00m\n");

}

void 	test_puts(char *str)
{
	printf("\n\033[33m------- Test Puts -------\033[00m\n");
	write(1, "\nPuts : ", 8);
	puts(str);
	write(1, "\nFt_puts : ", 11);
	ft_puts(str);
} 	

void 	test_strlen(char *str)
{
	printf("\n\033[33m------- Test Strlen -------\033[00m\n");
	printf("\nValue : %s\n", str);
	printf("\nStrlen : %d\n",(int)strlen(str));
	printf("\nFt_strlen : %d\n",ft_strlen(str));
} 	

void 	test_strdup(char *str)
{
	char *str1;
	char *str2;
	
	str1 = strdup(str);
	str2 = ft_strdup(str);
	printf("\n\033[33m------- Test Strdup -------\033[00m\n");
	printf("\nString : %s\n\nAdresse string : %p\n", str, str);
	printf("\n\n--Strdup--\n\nValue : %s\n\nadresse : %p",str1, str1);
	printf("\n\n\n--Ft_strdup--\n\nValue : %s\n\nadresse : %p",str2, str2);
	
}

void test_memcpy(char **argv)
{
	char *str;

	str = ft_strdup("0000000000000");
	printf("\n\033[33m------- Test Memcpy -------\033[00m\n");
	printf("\n\nOriginal string : %s\n\n",str);
	
	memcpy(str, argv[2], atoi(argv[3]));
	
	printf("\nChain swap : %s\n", argv[2]);
	printf("\n\nNb Bit swap : %d\n", atoi(argv[3]));
	printf("\n\n__Memcpy : %s\n\n",str);
	
	str = ft_strdup("0000000000000");
	
	ft_memcpy(str, argv[2], atoi(argv[3]));
	printf("\n__Ft_memcpy : %s\n",str);
}

void test_memset(char **argv)
{
	char *str;

	str = ft_strdup("0000000000000");
	printf("\n\033[33m------- Test Memset -------\033[00m\n");
	printf("\n\nOriginal string : %s\n\n",str);
	
	memset(str, argv[2][0], atoi(argv[3]));
	
	printf("\nCharactere set : %c\n", argv[2][0]);
	printf("\n\nNb Bit set : %d\n", atoi(argv[3]));
	printf("\n\n__Memset : %s\n\n",str);
	
	str = ft_strdup("0000000000000");
	
	ft_memset(str, argv[2][0], atoi(argv[3]));
	printf("\n__Ft_memset : %s\n",str);
}

void test_cat(char **argv)
{
	int fd;

	if(argv[2][0] != '0')
	{
		if((fd = open(argv[2], O_RDONLY)) != -1)
			ft_cat(fd);
		close(fd);
	}
	else
		ft_cat(0);
}

void test_strnew(char **argv)
{
	int x;
	size_t y;
	char *str;

	x = atoi(argv[2]);
	y = 0;
	str = ft_strnew(x);
	printf("\n\033[33m------- Test Strnew -------\033[00m\n");
	while(y <= 50)
	{
		printf("\nBit %d : %d", (int)y, str[y]);
		if(y == x - 1)
			printf("     ! string last byte !   ");
		y++;
	}
}

void test_strclr(char *str1)
{
	int x;
	int y;
	char *str;

	x = 0;
	y = ft_strlen(str1);
	str = ft_strdup(str1);
	printf("\n\033[33m------- Test Strclr -------\033[00m\n");
	printf("\n\n__ Original string __\n\nValue : %s\n\n", str);
	ft_strclr(str);
	printf("String Adresse : %p\n\n\n", str);
	printf("__ String >> Ft_strclr __\n\nValue : ");
	ft_strclr(str);
	while(x < y)
	{
		printf("%d", str[x]);
		x++;
	}
	printf("\n\nString Adresse : %p", str);
}

void test_memalloc(char **argv)
{
	int x;
	size_t y;
	char *str;

	x = atoi(argv[2]);
	y = 0;
	str = ft_memalloc(x);
	printf("\n\033[33m------- Test ft_memalloc -------\033[00m\n");
	while(y <= 50)
	{
		printf("\nBit %d : %d", (int)y, str[y]);
		if(y == x - 1)
			printf("     ! last byte alloc !  ");
		y++;
	}
}

int main(int argc, char **argv)
{
	if(argc > 1)
	{
		if(strcmp(argv[1] , "is") == 0 && argc == 2)
		{
			test_is();
			test_strcat();
			test_bzero();
		}
		else if(strcmp(argv[1], "puts") == 0 && argc == 3)
			test_puts(argv[2]);
		else if(strcmp(argv[1], "strlen") == 0 && argc == 3)
			test_strlen(argv[2]);
		else if(strcmp(argv[1], "strdup") == 0 && argc == 3)
			test_strdup(argv[2]);
		else if(strcmp(argv[1], "memcpy" ) == 0 && argc == 4)
			test_memcpy(argv);
		else if(strcmp(argv[1], "memset" ) == 0 && argc == 4)
			test_memset(argv);
		else if(strcmp(argv[1], "cat") == 0 && argc == 3)
			test_cat(argv);
		else if(strcmp(argv[1], "strnew") == 0 && argc == 3)
			test_strnew(argv);
		else if(strcmp(argv[1], "strclr") == 0 && argc == 3)
			test_strclr(argv[2]);
		else if(strcmp(argv[1], "memalloc") == 0 && argc == 3)
			test_memalloc(argv);
		else
			printf("Arguments Missing or false \n");

		return(0);
	}
	else
		printf("Arguments Missing or false\n");

}
