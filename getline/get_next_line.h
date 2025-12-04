/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:21:04 by agkicina          #+#    #+#             */
/*   Updated: 2025/11/17 14:27:52 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_update_stash(char *old_stash);
char	*ft_strchr(const char *s, int c);
size_t	f_strlen(const char *s);
char	*f_strdup(const char *s);
char	*get_next_line(int fd);
char	*f_strjoin(char *s1, char *s2);
size_t	f_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_extract(char *s);
#endif
