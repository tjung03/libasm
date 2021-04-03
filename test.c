/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:54:42 by tjung             #+#    #+#             */
/*   Updated: 2021/04/04 02:48:23 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//size_t		ft_strlen(char *s);
//char		*ft_strcpy(char *dst, char *src);
//int			ft_strcmp(char *s1, char *s2);
//ssize_t		ft_write(int filds, void *buf, size_t nbyte);
//ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
//char		*ft_strdup(char *s1);

int			main(int ac, char **av)
{
/*
	// ft_strlen
	int		len;

	len = ft_strlen(av[0]);
	printf("%s %d\n", av[0], len);
	*/

/*
	// ft_strcpy
	char	*s = "test";
	char	*d;

	d = malloc(sizeof(char) * 5);
	ft_strcpy(d, s);
	printf("s : %s\n", s);
	printf("d : %s\n", d);
	*/

/*
	// ft_strcmp
	int		ret;
	char	*s1 = "test";
	char	*s2 = "test";

	printf("s1 : %s\n", s1);
	printf("s2 : %s\n", s2);
	printf("----ft----\n");
	ret = ft_strcmp(s1, s2);
	printf("ft_strcmp -> %d\n", ret);
	printf("----og----\n");
	ret = strcmp(s1, s2);
	printf("strcmp -> %d\n", ret);
	*/

/*
	// ft_write 
	int		ret;
	
	printf("----og----\n");
	ret = write(1, "og_test\n", 8);
	printf("og ret : %d\n", ret);
	usleep(100);
	printf("----ft----\n");
	ret = ft_write(1, "ft_test\n", 8);
	printf("ft ret : %d\n", ret);
	*/

/*
	// ft_read
	int		ret;
	char	buf[9];
	
	buf[8] = '\0';
	printf("----og----\n");
	ret = read(0, buf, 8);
	printf("og ret : %d\n", ret);
	printf("og : %s\n", buf);
	printf("----ft----\n");
	ret = ft_read(0, buf, 8);
	printf("ft ret : %d\n", ret);
	printf("og : %s\n", buf);
	*/

/*
	// ft_strdup
	char	*s1 = "test";
	char	*s2;

	printf("s1 : %s\n", s1);
	printf("s2 : %s\n", s2);
	printf("----ft----\n");
	s2 = ft_strdup(s1);
	printf("s2 : %s\n", s2);
	printf("----og----\n");
	s2 = strdup(s1);
	printf("s2 : %s\n", s2);
	*/
	return (0);
}
