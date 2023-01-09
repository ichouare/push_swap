/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextLine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:34:10 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/09 18:44:00 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static char	*heandler_next_line(char **svr, char *line)
{
	char	*tmp;
	int		index;

	index = 0;
	if (found_nl(*svr, '\0') == 0)
	{
		free(*svr);
		*svr = NULL;
		return (NULL);
	}
	if (ft_strchr(*svr, '\n'))
	{
		index = found_nl(*svr, '\n');
		line = ft_substr(*svr, 0, index);
		tmp = *svr;
		*svr = ft_substr(*svr, index + 1, found_nl(*svr, '\0') + 1);
		free(tmp);
	}
	else
	{
		line = ft_substr(*svr, 0, found_nl(*svr, '\0') + 1);
		free(*svr);
		*svr = NULL;
	}
	return (line);
}

static char	*handler_line( char **svr, char **buffer, int fd , int BUFFER_SIZE)
{
	char			*tmp;
	ssize_t			sz;

	sz = 1;
	while (ft_strchr(*svr, '\n') == NULL && sz != 0)
	{
		sz = read(fd, *buffer, BUFFER_SIZE);
		if (sz <= -1)
		{
			free(*buffer);
			free(*svr);
			return (NULL);
		}
		tmp = *svr;
		*svr = ft_strjoin(*svr, *buffer);
		free(tmp);
		tmp = NULL;
		ft_bzero(*buffer, found_nl(*buffer, '\0') + 1);
	}
	return (*svr);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*svr;
	char		*line;
    int         BUFFER_SIZE = 1;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!svr)
		svr = ft_substr(buffer, 0, found_nl(buffer, '\0'));
	svr = handler_line(&svr, &buffer, fd, BUFFER_SIZE);
	if (!svr)
		return (NULL);
	free(buffer);
    return (heandler_next_line(&svr, line));
}