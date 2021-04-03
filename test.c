/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:54:42 by tjung             #+#    #+#             */
/*   Updated: 2021/04/04 00:07:52 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//size_t		ft_strlen(char *s);
//char		*ft_strcpy(char *dst, char *src);
//int			ft_strcmp(char *s1, char *s2);
ssize_t		write(int filds, void *buf, size_t nbyte);

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
	return (0);
}
