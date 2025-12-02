/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:21:04 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/02 14:16:37 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
size_t	f_strlen(const char *s);
char	*f_strdup(const char *s);
char	*get_next_line(int fd);
char	*f_strjoin(char *s1, char *s2);
size_t	f_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_update_stash(char *stash);
char	*ft_extract_word(char *s);

#endif
