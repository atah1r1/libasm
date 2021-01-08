/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:32:02 by atahiri           #+#    #+#             */
/*   Updated: 2021/01/08 11:43:14 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

size_t		ft_strlen(char const *str);
char        *ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);

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

	printf("\n================================\n");
	printf("========== FT_STRLEN ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: %zu\n", "MAIN", strlen(empty));	
	printf("%-20s: %zu\n", "LIBASM", ft_strlen(empty));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: %zu\n", "MAIN", strlen(hello_world));	
	printf("%-20s: %zu\n", "LIBASM", ft_strlen(hello_world));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", alphabet);
	printf("%-20s: %zu\n", "MAIN", strlen(alphabet));	
	printf("%-20s: %zu\n", "LIBASM", ft_strlen(alphabet));
	printf("\n");
}

void check_strcpy()
{
	char buffer[30];
	
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	printf("\n================================\n");
	printf("========== FT_STRCPY ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char []", empty);
	printf("%-20s: buffer[30]\n", "copy to");
	printf("%-20s: \"%s\"\n", "MAIN", strcpy(buffer, empty));	
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "LIBASM", ft_strcpy(buffer, empty));	
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", hello_world);
	printf("%-20s: buffer[30]\n", "copy to");
	printf("%-20s: \"%s\"\n", "MAIN", strcpy(buffer, hello_world));	
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "LIBASM", ft_strcpy(buffer, hello_world));	
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", alphabet);
	printf("%-20s: buffer[30]\n", "copy to");
	printf("%-20s: \"%s\"\n", "MAIN", strcpy(buffer, alphabet));	
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "LIBASM", ft_strcpy(buffer, alphabet));
	clear_buffer(buffer, 30);
	printf("\n");
}

void check_strcmp()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *hello_human = "Hello human !";
	char *hello_world2 = "Hello world !";
	
	printf("\n================================\n");
	printf("========== FT_STRCMP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_human);
	printf("%-20s: \"%d\"\n", "MAIN", strcmp(hello_world, hello_human));
	printf("%-20s: \"%d\"\n", "LIBASM", ft_strcmp(hello_world, hello_human));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_world2);
	printf("%-20s: \"%d\"\n", "MAIN", strcmp(hello_world, hello_world2));
	printf("%-20s: \"%d\"\n", "LIBASM", ft_strcmp(hello_world, hello_world2));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world2);
	printf("%-20s: \"%s\"\n", "compared to", empty);
	printf("%-20s: \"%d\"\n", "MAIN", strcmp(hello_world2, empty));
	printf("%-20s: \"%d\"\n", "LIBASM", ft_strcmp(hello_world2, empty));
	printf("\n");
}

void		check_write()
{
	char *buff = "Hello world\n";
	printf("\n================================\n");
	printf("=========== FT_WRITE ===========\n");
	printf("================================\n\n");
	printf("MAIN: %zd", write(1, buff, ft_strlen(buff)));
	printf("\n");
	printf("LIBASM: %zd", ft_write(1, buff, ft_strlen(buff)));
	printf("\n");
	printf("TESTING NULL BUFFER MAIN FUNCTION:\n");
	printf("MAIN: %zd", write(1, NULL, 1));
	printf("\n");
	printf("TESTING NULL BUFFER LIBASM FUNCTION:\n");
	printf("LIBASM: %zd", ft_write(1, NULL, 1));
}

int     main()
{
    check_strlen();
    check_strcpy();
	check_strcmp();
	check_write();
}