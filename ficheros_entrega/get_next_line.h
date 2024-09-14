/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valvarez <valvarez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:15:44 by valvarez          #+#    #+#             */
/*   Updated: 2024/09/12 20:15:50 by valvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* libft functions */
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
void	*ft_calloc(size_t count, size_t size);
/* new functions */
char	*get_line_start(const char *str);
char	*get_line_end(const char *str);
void	read_line(int fd, char **storage);
char	*process_current_line(char **storage);
void	ft_free_strs(char **str, char **str1, char **str2);
char	*get_next_line(int fd);

#endif
