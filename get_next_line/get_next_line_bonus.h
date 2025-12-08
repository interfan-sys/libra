/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:40:01 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/08 11:40:54 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif

# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char	*read_fill_stash(int fd, char *stash);
char	*ft_update_stash(char *old_stash);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_free_stash(char	*stash);
char	*ft_strdup(const char *s);
char	*get_next_line_bonus(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_extract(char *s);

#endif
