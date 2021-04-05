/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:54:42 by tjung             #+#    #+#             */
/*   Updated: 2021/04/06 01:40:25 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t		ft_strlen(char *s);
char		*ft_strcpy(char *dst, char *src);
int			ft_strcmp(char *s1, char *s2);
ssize_t		ft_write(int filds, void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
char		*ft_strdup(char *s1);

int			main(int ac, char **av)
{
	int		len;
	int		ret;
	char	*s1 = "test";
	char	*d;
	char	buf[9];

	// ft_strlen
	printf("====ft_strlen====\n");
	len = ft_strlen(av[0]);
	printf("%s %d\n", av[0], len);

	// ft_strcpy
	printf("\n====ft_strcpy====\n");
	d = malloc(sizeof(char) * 5);
	ft_strcpy(d, s1);
	printf("s1 : %s\n", s1);
	printf("d : %s\n", d);

	// ft_strcmp
	printf("\n====ft_strcmp====\n");
	printf("s1 : %s\n", s1);
	printf("d : %s\n", d);
	printf("----og----\n");
	ret = strcmp(s1, d);
	printf("strcmp -> %d\n", ret);
	printf("----ft----\n");
	ret = ft_strcmp(s1, d);
	printf("ft_strcmp -> %d\n", ret);

	// ft_write
	printf("\n====ft_write====\n");
	printf("----og----\n");
	ret = write(1, "og_test\n", 8);
	printf("og ret : %d\n", ret);
	usleep(100);
	printf("----ft----\n");
	ret = ft_write(1, "ft_test\n", 8);
	printf("ft ret : %d\n", ret);

	// ft_read
	printf("\n====ft_read====\n");
	for (int i = 0; i < 9; i++)
		buf[i] = 0;
	printf("----og----\n");
	ret = read(0, buf, 8);
	while (getchar() != '\n');
	printf("og ret : %d\n", ret);
	printf("og : %s\n", buf);
	printf("----ft----\n");
	ret = ft_read(0, buf, 8);
	while (getchar() != '\n');
	printf("ft ret : %d\n", ret);
	printf("ft : %s\n", buf);

	// ft_strdup
	printf("\n====ft_strdup====\n");
	free(d);
	printf("s1 : %s\n", s1);
	printf("d : %s\n", d);
	printf("----ft----\n");
	d = ft_strdup(s1);
	printf("d : %s\n", d);
	printf("----og----\n");
	d = strdup(s1);
	printf("d : %s\n", d);
	return (0);
}
