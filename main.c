/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:32:02 by atahiri           #+#    #+#             */
/*   Updated: 2021/01/09 16:27:06 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

size_t		ft_strlen(char const *str);
char        *ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
char 		*ft_strdup(const char *s1);

void red() 
{
  printf("\033[1;31m");
}

void yellow() 
{
  printf("\033[1;33m");
}

void reset() 
{
  printf("\033[0m");
}

void green()
{
	printf("\033[0;32m");
}

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}

void check_strlen()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";
	red();
	printf("\n================================\n");
	printf("========== FT_STRLEN ===========\n");
	printf("================================\n\n");
	reset();
	printf("%-20s: \"%s\"\n", "char *", empty);
	yellow();
	printf("%-20s: %zu\n", "MAIN", strlen(empty));	
	green();
	printf("%-20s: %zu\n", "LIBASM", ft_strlen(empty));
	reset();
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	yellow();
	printf("%-20s: %zu\n", "MAIN", strlen(hello_world));
	green();	
	printf("%-20s: %zu\n", "LIBASM", ft_strlen(hello_world));
	reset();
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", alphabet);
	yellow();
	printf("%-20s: %zu\n", "MAIN", strlen(alphabet));
	green();	
	printf("%-20s: %zu\n", "LIBASM", ft_strlen(alphabet));
	reset();
	printf("\n");
}

void check_strcpy()
{
	char buffer[30];
	
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";
	red();
	printf("\n================================\n");
	printf("========== FT_STRCPY ===========\n");
	printf("================================\n\n");
	reset();
	printf("%-20s: \"%s\"\n", "char []", empty);
	printf("%-20s: buffer[30]\n", "copy to");
	yellow();
	printf("%-20s: \"%s\"\n", "MAIN", strcpy(buffer, empty));	
	green();
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "LIBASM", ft_strcpy(buffer, empty));	
	reset();
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", hello_world);
	printf("%-20s: buffer[30]\n", "copy to");
	yellow();
	printf("%-20s: \"%s\"\n", "MAIN", strcpy(buffer, hello_world));	
	green();
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "LIBASM", ft_strcpy(buffer, hello_world));	
	reset();
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", alphabet);
	printf("%-20s: buffer[30]\n", "copy to");
	yellow();
	printf("%-20s: \"%s\"\n", "MAIN", strcpy(buffer, alphabet));
	green();	
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "LIBASM", ft_strcpy(buffer, alphabet));
	reset();
	clear_buffer(buffer, 30);
	printf("\n");
}

void check_strcmp()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *hello_human = "Hello human !";
	char *hello_world2 = "Hello world !";
	red();
	printf("\n================================\n");
	printf("========== FT_STRCMP ===========\n");
	printf("================================\n\n");
	reset();
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_human);
	yellow();
	printf("%-20s: \"%d\"\n", "MAIN", strcmp(hello_world, hello_human));
	green();
	printf("%-20s: \"%d\"\n", "LIBASM", ft_strcmp(hello_world, hello_human));
	reset();
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_world2);
	yellow();
	printf("%-20s: \"%d\"\n", "MAIN", strcmp(hello_world, hello_world2));
	green();
	printf("%-20s: \"%d\"\n", "LIBASM", ft_strcmp(hello_world, hello_world2));
	reset();
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world2);
	printf("%-20s: \"%s\"\n", "compared to", empty);
	yellow();
	printf("%-20s: \"%d\"\n", "MAIN", strcmp(hello_world2, empty));
	green();
	printf("%-20s: \"%d\"\n", "LIBASM", ft_strcmp(hello_world2, empty));
	reset();
	printf("\n");
}

void		check_write()
{
	char *buff = "Hello world\n";
	red();
	printf("\n================================\n");
	printf("=========== FT_WRITE ===========\n");
	printf("================================\n\n");
	yellow();
	printf("MAIN: %zd", write(1, buff, ft_strlen(buff)));reset();
	reset();
	printf("\n");
	green();
	printf("LIBASM: %zd", ft_write(1, buff, ft_strlen(buff)));
	reset();
	printf("\n");
	printf("TESTING NULL BUFFER MAIN FUNCTION:\n");
	yellow();
	printf("MAIN: %zd", write(1, NULL, 1));
	reset();
	printf("\n");
	printf("TESTING NULL BUFFER LIBASM FUNCTION:\n");
	green();
	printf("LIBASM: %zd", ft_write(1, NULL, 1));
	reset();
}

void check_strdup()
{
	char *hello_world = "Hello world !";
	char *empty = "";
	char *save;
	char *save2;
	red();
	printf("\n================================\n");
	printf("========== FT_STRDUP ===========\n");
	printf("================================\n\n");
	reset();
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	save = strdup(hello_world);
	yellow();
	printf("%-20s: \"%s\"\n", "MAIN", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(hello_world);
	green();
	printf("%-20s: \"%s\"\n", "LIBASM", save2);
	free(save2);
	save2 = NULL;
	reset();
	printf("\n");

	printf("%-20s: \"%s\"\n", "char *", empty);
	save = strdup(empty);
	yellow();
	printf("%-20s: \"%s\"\n", "MAIN", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(empty);
	green();
	printf("%-20s: \"%s\"\n", "LIBASM", save2);
	free(save2);
	save2 = NULL;
	reset();
	printf("\n");
}

void check_read()
{
	int fd = open("file.txt", O_RDONLY);
	char buff1[1024];
	int ret = 1;
	red();
	printf("\n================================\n");
	printf("========== FT_READ =============\n");
	printf("================================\n\n");
	reset();
	yellow();
	printf("%-20s: \n", "MAIN:	header file.txt | read ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	reset();
	printf("[return : %d]\n[%s]\n", ret, buff1);
	printf("\n");
	close(fd);


	fd = open("file.txt", O_RDONLY);
	clear_buffer(buff1, 891);
	green();
	printf("%-20s: \n", "LIBASM:	header file.txt | ft_read ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	reset();
	printf("[return : %d]\n[%s]\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	printf("\n------------------------------\n\n");

	fd = open("wrong", O_RDONLY);
	yellow();
	printf("%-20s: \n", "header no_file.txt | read ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	reset();
	printf("[return : %d]\n[%s]\n", ret, buff1);
	printf("\n");
	close(fd);

	fd = open("wrong", O_RDONLY);
	clear_buffer(buff1, 891);
	green();
	printf("%-20s: \n", "header no_file.txt | ft_read ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	reset();
	printf("[return : %d]\n[%s]\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);
}

int     main()
{
    check_strlen();
    check_strcpy();
	check_strcmp();
	check_write();
	check_strdup();
	check_read();
}