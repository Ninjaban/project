/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:30:40 by mmarchan          #+#    #+#             */
/*   Updated: 2016/02/11 10:34:57 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftasm.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

# define C_BLUE		"\033[34m"
# define C_GREEN	"\033[32m"
# define C_NONE		"\033[0m"

///////////////////////////////////////////////////////////////

void	test_bzero(void)
{
	printf(C_GREEN"\n\n--- bzero ---\n"C_NONE);

	char str[5] = "waza";
	printf("before ft_bzero -> \'%s\'\n", str);
	ft_bzero((void *)str, 5);
	printf("after ft_bzero -> \'%s\'\n", str);
	char s[100];

	strcpy(s, "coucoucoucouocuocuocu");
	ft_bzero(s, 4);
	printf("TEST BZERO !! >  need 0 !! %d\n", memcmp(s, "\0\0\0\0ouc", 7));
}

void	test_strcat(void)
{
	printf(C_GREEN"\n\n--- strcat ---\n"C_NONE);

	char s1[50] = "qwerty";
	char s2[10] = "azerty";

	printf("s1 : \'%s\'\n",	s1);
	printf("s2 : \'%s\'\n",	s2);
	printf("strcat : \'%s\'\n",	ft_strcat(s1, s2));
	printf("s1 : \'%s\'\n",	s1);
	printf("s2 : \'%s\'\n",	s2);
	
	printf("Before s1 no cat : \'%s\'\n",	s1);
	ft_strcat(s1, "");
	printf("After s1 no cat : \'%s\'\n",	s1);
}

void	test_isalpha(void)
{
	printf(C_GREEN"\n\n--- isalpha ---\n"C_NONE);

	printf("ft_isalpha %c : %d == %d\n", 'a' - 1, ft_isalpha('a' - 1), isalpha('a' - 1));
	printf("ft_isalpha %c : %d == %d\n", 'a', ft_isalpha('a'), isalpha('a'));
	printf("ft_isalpha %c : %d == %d\n", 'z', ft_isalpha('z'), isalpha('z'));
	printf("ft_isalpha %c : %d == %d\n", 'z' + 1, ft_isalpha('z' + 1), isalpha('z' + 1));
	printf("ft_isalpha %c : %d == %d\n", 'A' - 1, ft_isalpha('A' - 1), isalpha('A' - 1));
	printf("ft_isalpha %c : %d == %d\n", 'A', ft_isalpha('A'), isalpha('A'));
	printf("ft_isalpha %c : %d == %d\n", 'Z', ft_isalpha('Z'), isalpha('Z'));
	printf("ft_isalpha %c : %d == %d\n", 'Z' + 1, ft_isalpha('Z' + 1), isalpha('Z' + 1));
	printf("ft_isalpha %c : %d == %d\n", '$', ft_isalpha('$'), isalpha('$'));
	printf("ft_isalpha %c : %d == %d\n", '5', ft_isalpha('5'), isalpha('5'));;
}

void	test_isdigit(void)
{
	printf(C_GREEN"\n\n--- isdigit ---\n"C_NONE);

	printf("ft_isdigit %c : %d == %d\n", 'a' - 1, ft_isdigit('a' - 1), isdigit('a' - 1));
	printf("ft_isdigit %c : %d == %d\n", 'a', ft_isdigit('a'), isdigit('a'));
	printf("ft_isdigit %c : %d == %d\n", 'z', ft_isdigit('z'), isdigit('z'));
	printf("ft_isdigit %c : %d == %d\n", 'z' + 1, ft_isdigit('z' + 1), isdigit('z' + 1));
	printf("ft_isdigit %c : %d == %d\n", 'A' - 1, ft_isdigit('A' - 1), isdigit('A' - 1));
	printf("ft_isdigit %c : %d == %d\n", 'A', ft_isdigit('A'), isdigit('A'));
	printf("ft_isdigit %c : %d == %d\n", 'Z', ft_isdigit('Z'), isdigit('Z'));
	printf("ft_isdigit %c : %d == %d\n", 'Z' + 1, ft_isdigit('Z' + 1), isdigit('Z' + 1));
	printf("ft_isdigit %c : %d == %d\n", '$', ft_isdigit('$'), isdigit('$'));
	printf("ft_isdigit %c : %d == %d\n", '5', ft_isdigit('5'), isdigit('5'));;
}


void	test_isalnum(void)
{
	printf(C_GREEN"\n\n--- isalnum ---\n"C_NONE);

	printf("ft_isalnum %c : %d == %d\n", 'a' - 1, ft_isalnum('a' - 1), isalnum('a' - 1));
	printf("ft_isalnum %c : %d == %d\n", 'a', ft_isalnum('a'), isalnum('a'));
	printf("ft_isalnum %c : %d == %d\n", 'z', ft_isalnum('z'), isalnum('z'));
	printf("ft_isalnum %c : %d == %d\n", 'z' + 1, ft_isalnum('z' + 1), isalnum('z' + 1));
	printf("ft_isalnum %c : %d == %d\n", 'A' - 1, ft_isalnum('A' - 1), isalnum('A' - 1));
	printf("ft_isalnum %c : %d == %d\n", 'A', ft_isalnum('A'), isalnum('A'));
	printf("ft_isalnum %c : %d == %d\n", 'Z', ft_isalnum('Z'), isalnum('Z'));
	printf("ft_isalnum %c : %d == %d\n", 'Z' + 1, ft_isalnum('Z' + 1), isalnum('Z' + 1));
	printf("ft_isalnum %c : %d == %d\n", '$', ft_isalnum('$'), isalnum('$'));
	printf("ft_isalnum %c : %d == %d\n", '5', ft_isalnum('5'), isalnum('5'));;
}


void	test_isascii(void)
{
	printf(C_GREEN"\n\n--- isascii ---\n"C_NONE);

	printf("ft_isascii %c : %d == %d\n", 'a' - 1, ft_isascii('a' - 1), isascii('a' - 1));
	printf("ft_isascii %c : %d == %d\n", 'a', ft_isascii('a'), isascii('a'));
	printf("ft_isascii %c : %d == %d\n", 'z', ft_isascii('z'), isascii('z'));
	printf("ft_isascii %c : %d == %d\n", 'z' + 1, ft_isascii('z' + 1), isascii('z' + 1));
	printf("ft_isascii %c : %d == %d\n", 'A' - 1, ft_isascii('A' - 1), isascii('A' - 1));
	printf("ft_isascii %c : %d == %d\n", 'A', ft_isascii('A'), isascii('A'));
	printf("ft_isascii %c : %d == %d\n", 'Z', ft_isascii('Z'), isascii('Z'));
	printf("ft_isascii %c : %d == %d\n", 'Z' + 1, ft_isascii('Z' + 1), isascii('Z' + 1));
	printf("ft_isascii %c : %d == %d\n", '$', ft_isascii('$'), isascii('$'));
	printf("ft_isascii %c : %d == %d\n", '5', ft_isascii('5'), isascii('5'));;
	printf("ft_isascii \\n : %d == %d\n", ft_isascii('\n'), isascii('\n'));
	printf("ft_isascii -1 : %d == %d\n", ft_isascii(-1), isascii(-1));
	printf("ft_isascii \'%c\' : %d == %d\n", ' ', ft_isascii(' '), isascii(' '));
}

void	test_isprint(void)
{
	printf(C_GREEN"\n\n--- isprint ---\n"C_NONE);

	printf("ft_isprint %c : %d == %d\n", 'a' - 1, ft_isprint('a' - 1), isprint('a' - 1));
	printf("ft_isprint %c : %d == %d\n", 'a', ft_isprint('a'), isprint('a'));
	printf("ft_isprint %c : %d == %d\n", 'z', ft_isprint('z'), isprint('z'));
	printf("ft_isprint %c : %d == %d\n", 'z' + 1, ft_isprint('z' + 1), isprint('z' + 1));
	printf("ft_isprint %c : %d == %d\n", 'A' - 1, ft_isprint('A' - 1), isprint('A' - 1));
	printf("ft_isprint %c : %d == %d\n", 'A', ft_isprint('A'), isprint('A'));
	printf("ft_isprint %c : %d == %d\n", 'Z', ft_isprint('Z'), isprint('Z'));
	printf("ft_isprint %c : %d == %d\n", 'Z' + 1, ft_isprint('Z' + 1), isprint('Z' + 1));
	printf("ft_isprint %c : %d == %d\n", '$', ft_isprint('$'), isprint('$'));
	printf("ft_isprint %c : %d == %d\n", '5', ft_isprint('5'), isprint('5'));;
	printf("ft_isprint \\n : %d == %d\n", ft_isprint('\n'), isprint('\n'));
	printf("ft_isprint -1 : %d == %d\n", ft_isprint(-1), isprint(-1));
	printf("ft_isprint \'%c\' : %d == %d\n", ' ', ft_isprint(' '), isprint(' '));
}

void	test_toupper(void)
{
	printf(C_GREEN"\n\n--- toupper ---\n"C_NONE);

	printf("ft_toupper %c : %c == %c\n", 'a' - 1, ft_toupper('a' - 1), toupper('a' - 1));
	printf("ft_toupper %c : %c == %c\n", 'a', ft_toupper('a'), toupper('a'));
	printf("ft_toupper %c : %c == %c\n", 'z', ft_toupper('z'), toupper('z'));
	printf("ft_toupper %c : %c == %c\n", 'z' + 1, ft_toupper('z' + 1), toupper('z' + 1));
	printf("ft_toupper %c : %c == %c\n", 'A' - 1, ft_toupper('A' - 1), toupper('A' - 1));
	printf("ft_toupper %c : %c == %c\n", 'A', ft_toupper('A'), toupper('A'));
	printf("ft_toupper %c : %c == %c\n", 'Z', ft_toupper('Z'), toupper('Z'));
	printf("ft_toupper %c : %c == %c\n", 'Z' + 1, ft_toupper('Z' + 1), toupper('Z' + 1));
	printf("ft_toupper %c : %c == %c\n", '$', ft_toupper('$'), toupper('$'));
	printf("ft_toupper %c : %c == %c\n", '5', ft_toupper('5'), toupper('5'));;
	printf("ft_toupper \\n : %c == %c\n", ft_toupper('\n'), toupper('\n'));
	printf("ft_toupper -1 : %c == %c\n", ft_toupper(-1), toupper(-1));
	printf("ft_toupper \'%c\' : %c == %c\n", ' ', ft_toupper(' '), toupper(' '));
}

void	test_tolower(void)
{
	printf(C_GREEN"\n\n--- tolower ---\n"C_NONE);

	printf("ft_tolower %c : %c == %c\n", 'a' - 1, ft_tolower('a' - 1), tolower('a' - 1));
	printf("ft_tolower %c : %c == %c\n", 'a', ft_tolower('a'), tolower('a'));
	printf("ft_tolower %c : %c == %c\n", 'z', ft_tolower('z'), tolower('z'));
	printf("ft_tolower %c : %c == %c\n", 'z' + 1, ft_tolower('z' + 1), tolower('z' + 1));
	printf("ft_tolower %c : %c == %c\n", 'A' - 1, ft_tolower('A' - 1), tolower('A' - 1));
	printf("ft_tolower %c : %c == %c\n", 'A', ft_tolower('A'), tolower('A'));
	printf("ft_tolower %c : %c == %c\n", 'Z', ft_tolower('Z'), tolower('Z'));
	printf("ft_tolower %c : %c == %c\n", 'Z' + 1, ft_tolower('Z' + 1), tolower('Z' + 1));
	printf("ft_tolower %c : %c == %c\n", '$', ft_tolower('$'), tolower('$'));
	printf("ft_tolower %c : %c == %c\n", '5', ft_tolower('5'), tolower('5'));;
	printf("ft_tolower \\n : %c == %c\n", ft_tolower('\n'), tolower('\n'));
	printf("ft_tolower -1 : %c == %c\n", ft_tolower(-1), tolower(-1));
	printf("ft_tolower \'%c\' : %c == %c\n", ' ', ft_tolower(' '), tolower(' '));
}


void	test_puts(void)
{
	printf(C_GREEN"\n\n--- puts ---\n"C_NONE);

	char str[5] = "waza";
	
	ft_puts("\'test ft_puts\'");
	ft_puts(str);
	ft_puts("\'test puts(NULL)\'");
	puts(NULL);
	ft_puts("\'test ft_puts(NULL)\'");
	ft_puts(NULL);
}


void	test_strlen(void)
{
	printf(C_GREEN"\n\n--- strlen ---\n"C_NONE);

	char str[5] = "waza";
	char str2[10] = "123456789";
	
	printf("ft_strlen %s : %d == %d\n", str, (int)ft_strlen(str), (int)strlen(str));
	printf("ft_strlen %s : %d == %d\n", str2, (int)ft_strlen(str2), (int)strlen(str2));
	printf("need 0 : %zu\n", ft_strlen(""));
}

void	test_memset(void)
{
	printf(C_GREEN"\n\n--- memset ---\n"C_NONE);

	char s1[5] = "waza";
	char s2[5] = "waza";


	printf("before ft_memset\n");
	printf("s : \'%s\' == \'%s\'\n", s1, s2);
	printf("ft_memset(s1, \'x\', 3) : \'%s\'\n", ft_memset(s1, 'x', 3));
	printf("memset(s2, \'x\', 3) : \'%s\'\n", memset(s2, 'x', 3));
	printf("after ft_memset\n");
	printf("s : \'%s\' == \'%s\'\n", s1, s2);
}

void	test_memcpy(void)
{
	printf(C_GREEN"\n\n--- memcpy ---\n"C_NONE);
	
	char *src1;
	char *dst1;
	src1 = (char *)malloc(sizeof(char) * 5);
	dst1 = (char *)malloc(sizeof(char) * 5);
	src1 = "azer";

	char *src2;
	char *dst2;
	src2 = (char *)malloc(sizeof(char) * 5);
	dst2 = (char *)malloc(sizeof(char) * 5);
	src2 = "azer";

	printf("before ft_memcpy\n");
	printf("s : \'%s\' == \'%s\'\n", src1, src2);
	printf("d : \'%s\' == \'%s\'\n", dst1, dst2);
	printf("ft_memcpy : \'%s\'\n", (char *)ft_memcpy(dst1, src1, 5));
	printf("memcpy    : \'%s\'\n", (char *)memcpy(dst2, src2, 5));
	printf("after ft_memcpy\n");
	printf("s : \'%s\' == \'%s\'\n", src1, src2);
	printf("d : \'%s\' == \'%s\'\n", dst1, dst2);
	char s[100];

	bzero(s, 100);
	memset(s, 'x', 10);
	memcpy(s + 5, "coucou", 6);
	printf(" coucou ? : %s\n", s);
}


void	test_strdup(void)
{
	printf(C_GREEN"\n\n--- strdup ---\n"C_NONE);

	char *s1;
	char *s2;
	char *d1;
	char *d2;

	s1 = (char *)malloc(sizeof(char) * 5);
	s2 = (char *)malloc(sizeof(char) * 5);

	s1 = "azer";
	s2 = "azer";

	d1 = ft_strdup(s1);
	d2 = ft_strdup(s2);
	printf("before ft_strdup\n");
	printf("s : \'%s\' == \'%s\'\n", s1, s2);
	printf("ft_strdup : \'%s\'\n", (char *)ft_strdup(s1));
	printf("strdup    : \'%s\'\n", (char *)strdup(s2));
	printf("after ft_strdup\n");
	printf("s : \'%s\' == \'%s\'\n", s1, s2);
	printf("d : \'%s\' == \'%s\'\n", d1, d2);
	free(d1);
	free(d2);
}


void	test_cat(void)
{
	printf(C_GREEN"\n\n--- cat ---\n"C_NONE);

	int fd;	
	fd = open("Makefile", O_RDONLY);
	ft_cat(fd);
	close(fd);
//	ft_cat(0);
	ft_cat(-1);
}

////////////////////////////////////////////////////////////////////////////


int main(void)
{
	printf(C_BLUE"\n\n----------- P1 ! -------------\n"C_NONE);
	test_bzero();
	test_strcat();
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();
	test_puts();

	printf(C_BLUE"\n\n----------- P2 ! -------------\n"C_NONE);
	test_strlen();
	test_memset();
	test_memcpy();
	test_strdup();

	printf(C_BLUE"\n\n----------- P3 ! -------------\n"C_NONE);	
	test_cat();
	return  (0);
}

























