/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 02:11:17 by tjung             #+#    #+#             */
/*   Updated: 2021/04/06 02:12:14 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

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

#endif
