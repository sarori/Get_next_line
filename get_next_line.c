/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 22:32:29 by sapark            #+#    #+#             */
/*   Updated: 2019/05/28 20:27:42 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> //open함수 only
#include <stdio.h>

static int		line_check(const int fd, int idx, char **line, char **res)
{
	*line = ft_strsub(res[fd], 0, idx);
	ft_strcpy(res[fd], &res[fd][idx + 1]);
	return (1);
}

static void		element_check(const int fd, char **res,
								char *buf, int	read_count)
{
	char	*tmp;

	if (BUFF_SIZE > read_count)
		buf[read_count] = '\0';
	else
		buf[BUFF_SIZE] = '\0';
	tmp = ft_strjoin(res[fd], buf);
	free(res[fd]);
	res[fd] = tmp;
}

int		get_next_line(const int fd, char **line)
{
	int			idx;
	int			read_count;
	char		buf[BUFF_SIZE + 1];
	static char	*res[4096] = {0};

	idx = 0;
	if(!res[fd])
		res[fd] = ft_strnew(1);
	while ((read_count = read(fd, buf, BUFF_SIZE)) > 0)
	{
		element_check(fd, res, buf, read_count);
		if ((idx = ft_strchr_idx(res[fd], '\n')) >= 0)
			return (line_check(fd, idx, line, res));
		else if ((BUFF_SIZE > read_count) && idx < 0)
			return (line_check(fd, ft_strlen(res[fd]), line, res));
	}
	if (res[fd])
	{
		while ((idx = ft_strchr_idx(res[fd], '\n')) >= 0)
			return (line_check(fd, idx, line, res));
	}
	if (read_count == 0 && !res[fd])
		return (0);
	else
		return (-1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);

	char	*line = NULL;
	int		fd = open(av[1], O_RDONLY);

	while (get_next_line(fd, &line) > 0)
	{
		printf("[read line] : %s\n", line);
		free(line);
		line = NULL;
	}
	return (0);
}

