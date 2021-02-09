/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maadam <maadam@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:24:46 by maadam            #+#    #+#             */
/*   Updated: 2020/11/27 16:24:46 by maadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include "libasm.h"

void	ft_strlen_check(char **str)
{
	int		orig;
	int		my;
	int		i = -1;

	while (++i < 4)
	{	
		printf("STRING:\n\"%s\"\n\n", (str[i]));
		printf("Or function = %d\n", orig = strlen(str[i]));
		printf("My function = %d\n", my = ft_strlen(str[i]));
		printf("\n------------------------------------------\n\n");
	}
}

void	ft_strcpy_check(char **str)
{
	char	orig_dst[1000];
	char	my_dst[1000];
	int		i = -1;

	while (++i < 4)
	{
		strcpy(orig_dst, str[i]);
		ft_strcpy(my_dst, str[i]);
		i == 3 ? printf("SCR string   = |%s|\n\n", str[i]) : 
					printf("SRC string   = |%s|\n", str[i]);
		i == 3 ? printf("Orig strcpy  = |%s|\n\n", orig_dst) : 
					printf("Orig strcpy  = |%s|\n", orig_dst);
		printf("My ft_strcpy = |%s|\n\n", my_dst);
		
		int		len;
		printf("Orig  strcpy len = %d\n", len = strlen(orig_dst));
		printf("My ft_strcpy len = %d\n\n", len = ft_strlen(my_dst));
		printf("------------------------------------------------------------\n\n");

	}
}

void	ft_strcmp_check(char **str)
{
	int		orig;
	int		my;
	int		i = -1;

	while (++i < 3)
	{
		printf("Or function = %d\n", orig = strcmp(str[i], str[i + 1]));
		printf("My function = %d\n", my = ft_strcmp(str[i], str[i + 1]));
	}
}

void	ft_write_check(char *str)
{
	int		orig;
	int		my;
	
	write(1, "Orig write with normal string: ", strlen("Orig write with normal string: "));
	if ((orig = write(1, str, strlen(str))) < 0)
		printf("\nFunction returned: %d  |  Error %d: %s\n\n", orig, errno, strerror(errno));
	else
		printf("\nFunction returned: %d  |  No errors\n\n", orig);
	write(1, "  My write with normal string: ", strlen("  My write with normal string: "));
	if ((my = ft_write(1, str, strlen(str))) < 0)
		printf("\nFunction returned: %d  |  Error %d: %s\n\n", my, errno, strerror(errno));
	else
		printf("\nFunction returned: %d  |  No errors\n\n", my);

	printf("-----------------------------------------------------------------\n\n");
	
	write(1, "Orig write with bad FD: ", strlen("Orig write with bad FD: "));
	if ((orig = write(-42, str, strlen(str))) < 0)
		printf("\nFunction returned: %d  |  Error %d: %s\n\n", orig, errno, strerror(errno));
	else
		printf("\nFunction returned: %d  |  No errors\n\n", orig);
	write(1, "  My write with bad FD: ", strlen("  My write with bad FD: "));
	if ((my = ft_write(-42, str, strlen(str))) < 0)
		printf("\nFunction returned: %d  |  Error %d: %s\n\n", my, errno, strerror(errno));
	else
		printf("\nFunction returned: %d  |  No errors\n\n", my);

	printf("-----------------------------------------------------------------\n\n");

	write(1, "Orig write with negative nbytes : ", strlen("Orig write with negative nbytes: "));
	if ((orig = write(1, str, -10)) < 0)
		printf("\nFunction returned: %d  |  Error %d: %s\n\n", orig, errno, strerror(errno));
	else
		printf("\nFunction returned: %d  |  No errors\n\n", orig);
	write(1, "  My write with negative nbytes: ", strlen("  My write with negative nbytes: "));
	if ((my = ft_write(1, str, -10)) < 0)
		printf("\nFunction returned: %d  |  Error %d: %s\n\n", my, errno, strerror(errno));
	else
		printf("\nFunction returned: %d  |  No errors\n\n", my);
}

void	ft_read_check(char **s)
{
	char	str[100];
	int		fd = open("test.txt", O_RDONLY);
	int		orig;
	int		my;

	printf("Orig read with bad FD: ");
	if ((orig = read(-42, str, 100)) < 0)
		printf("\nFunction returned: %d  |  Error %d: %s\n\n", orig, errno, strerror(errno));
	else
		printf("\nFunction returned: %d  |  No errors\n\n", orig);
	printf("  My read with bad FD: ");
	if ((my = ft_read(-42, str, 100)) < 0)
		printf("\nFunction returned: %d  |  Error %d: %s\n\n", my, errno, strerror(errno));
	else
		printf("\nFunction returned: %d  |  No errors\n\n", my);

	printf("-----------------------------------------------------------------\n\n");

	printf("Orig read with negative nbytes: ");
	if ((orig = read(0, str, -10)) < 0)
		printf("\nFunction returned: %d  |  Error %d: %s\n\n", orig, errno, strerror(errno));
	else
		printf("\nFunction returned: %d  |  No errors\n\n", orig);
	printf("  My read with negative nbytes: ");
	if ((my = ft_read(0, str, -10)) < 0)
		printf("\nFunction returned: %d  |  Error %d: %s\n\n", my, errno, strerror(errno));
	else
		printf("\nFunction returned: %d  |  No errors\n\n", my);

	printf("-----------------------------------------------------------------\n\n");

	printf("Orig read with text file (test.txt): ");
	if ((orig = read(fd, str, 100)) < 0)
		printf("\nFunction returned: %d  |  Error %d: %s\n\n", orig, errno, strerror(errno));
	else
		printf("\nFunction returned: %d  |  No errors\n\n", orig);

	fd = open("test.txt", O_RDONLY);
	printf("  My read with text file (test.txt): ");
	if ((my = ft_read(fd, str, 100)) < 0)
		printf("\nFunction returned: %d  |  Error %d: %s\n\n", my, errno, strerror(errno));
	else
		printf("\nFunction returned: %d  |  No errors\n\n", my);

	printf("-----------------------------------------------------------------\n\n");

	write(1, "Orig read with std input: ", strlen("Orig read with std input: "));
	if ((orig = read(0, &str, 10)) < 0)
		printf("\nFunction returned: %d  |  Error %d: %s\n\n", orig, errno, strerror(errno));
	else
		printf("\nFunction returned: %d  |  No errors\n\n", orig);
	write(1, "  My read with std input: ", strlen("  My read with std input: "));
	if ((my = ft_read(0, &str, 10)) < 0)
		printf("\nFunction returned: %d  |  Error %d: %s\n\n", my, errno, strerror(errno));
	else
		printf("\nFunction returned: %d  |  No errors\n\n", my);
}

void	ft_strdup_check(char **str)
{
	char	*s;
	int		orig = 0;
	int		i = -1;

	while(++i < 4)
	{
		if (!(s = strdup(str[i])))
			printf("ORIG STRDUP || Function returned: %d  ||  Error %d: %s\n", orig, errno, strerror(errno));
		else
		{
			printf("\nORIG STRDUP || Function returned: %d  ||  No errors\n", orig);
			printf("String:\n\"%s\"\n\n", s);
		}
		if (!(s = ft_strdup(str[i])))
			printf("  MY STRDUP || Function returned: %d  ||  Error %d: %s\n", orig, errno, strerror(errno));
		else
		{
			printf("\n  MY STRDUP || Function returned: %d  ||  No errors\n", orig);
			printf("String:\n\"%s\"\n\n", s);
		}

		printf("-----------------------------------------------------------------\n\n");
	}
}

int		main(void)
{
	char 	*str[4] = 
		{
			"",
			"123",
			"abcdefghijklmnopqrstuvwxyz 0123456789",
			"...На краю дороги стоял дуб. Он был, вероятно, в десять раз старше\
 берез, составлявших лес, в десять раз толще и в два раза выше каждой березы. \
Это был огромный, в два обхвата дуб, с обломанными суками и корой, заросшей \
старыми болячками. С огромными, неуклюже, несимметрично растопыренными корявыми\
 руками и пальцами, он старым, сердитым и презрительным уродом стоял между \
улыбающимися березами. Только он один не хотел подчиниться обаянию весны и не \
хотел видеть ни весны, ни солнца. Этот дуб как будто говорил..."
		};

	// ft_strlen_check(str);
	// ft_strcpy_check(str);
	// ft_strcmp_check(str);
	// ft_write_check(str[1]);
	// ft_read_check(str);
	ft_strdup_check(str);

	return (0);
}