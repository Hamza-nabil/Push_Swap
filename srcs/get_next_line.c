/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 20:41:22 by hnabil            #+#    #+#             */
/*   Updated: 2021/06/07 18:56:07 by hnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rmp(char **new, int n, char **line, int fd)
{
	char	*temp;
	int		i;

	i = 0;
	while (new[fd][i] && new[fd][i] != '\n')
		i++;
	*line = ft_substr(new[fd], 0, i);
	if (!new[fd][i])
	{
		temp = new[fd];
		new[fd] = NULL;
		free(temp);
		return (0);
	}
	else
	{
		temp = new[fd];
		new[fd] = ft_strdup((new[fd]) + i + 1);
		free(temp);
	}
	if (!new[fd] || !*line)
		return (-1);
	if (n || (n == 0 && new[fd] != NULL))
		return (1);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*oldline[4864];
	char		*temp;
	int			n;

	buf = malloc(BUFFER_SIZE + 1);
	if (!line || fd < 0 || fd >= 4864 || BUFFER_SIZE <= 0 || \
	!buf || read(fd, buf, 0) == -1)
		return (-1);
	if (!oldline[fd])
		oldline[fd] = ft_strdup("");
	while ((!ft_strchr(oldline[fd], '\n')))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == 0)
			break ;
		if (n < 0)
			return (-1);
		temp = oldline[fd];
		buf[n] = '\0';
		oldline[fd] = ft_strjoin(oldline[fd], buf);
		free(temp);
	}
	free(buf);
	return (ft_rmp(oldline, n, line, fd));
}
