/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valvarez <valvarez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:09:35 by valvarez          #+#    #+#             */
/*   Updated: 2024/09/12 20:14:23 by valvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_start(const char *str)
{
	char	*res_memory;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	res_memory = ft_calloc(i + 1, sizeof * res_memory);
	if (!res_memory)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		res_memory[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res_memory[i] = str[i];
		i++;
	}
	return (res_memory);
}

char	*get_line_end(const char *str)
{
	char	*res_memory;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	j = 0;
	while (str && str[j])
		j++;
	res_memory = ft_calloc((j - i) + 1, sizeof * res_memory);
	if (!res_memory)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		res_memory[j] = str[i + j];
		j++;
	}
	return (res_memory);
}

void	read_line(int fd, char **storage)
{
	char	*mem_reserve;
	char	*tempo;
	long	readed;

	mem_reserve = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!mem_reserve)
		return ;
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, mem_reserve, BUFFER_SIZE);
		if (readed < 0)
		{
			ft_free_strs(&mem_reserve, storage, NULL);
			return ;
		}
		mem_reserve[readed] = '\0';
		tempo = *storage;
		*storage = ft_strjoin(*storage, mem_reserve);
		free (tempo);
		if (ft_strchr(*storage, '\n'))
			break ;
	}
	free (mem_reserve);
}

char	*process_current_line(char **storage)
{
	char	*line;
	char	*tempo;

	line = get_line_start(*storage);
	tempo = *storage;
	*storage = get_line_end(*storage);
	free (tempo);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	read_line(fd, &storage);
	if (storage != NULL && *storage != '\0')
		line = process_current_line(&storage);
	if (!line || *line == '\0')
	{
		ft_free_strs(&storage, &line, NULL);
		return (NULL);
	}
	return (line);
}
/*
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main (void)
{
    int fd; 
    char *line;

    fd = 0;

    fd = open("quijote.txt", O_RDONLY);
    if (fd == -1)
        return (-1);
    line = get_next_line(fd);
    while (line) 
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    //printf(">%d\n", line == NULL ? 1 : 0);
}*/