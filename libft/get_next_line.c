/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 15:13:24 by sapark            #+#    #+#             */
/*   Updated: 2019/08/01 00:26:14 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	line_check(int idx, char **line, char **res)
{
	*line = ft_strsub(*res, 0, idx);
	ft_strcpy(*res, *res + idx + 1);
	return (1);
}

static int	final_line_check(int idx, char **line, char **res)
{
	*line = ft_strsub(*res, 0, idx);
	ft_strdel(res);
	return (1);
}

static void	element_check(char **res,
	char *buf, int read_count)
{
	char	*tmp;

	buf[read_count] = '\0';
	tmp = ft_strjoin(*res, buf);
	free(*res);
	*res = tmp;
}

int			get_next_line(const int fd, char **line)
{
	int			idx;
	int			read_count;
	char		buf[BUFF_SIZE + 1];
	static char	*res[4096] = {0};

	if (read(fd, buf, 0) == -1 || fd < 0 || fd > 4096 || !line)
		return (-1);
	if (!res[fd])
		res[fd] = ft_strnew(1);
	while ((read_count = read(fd, buf, BUFF_SIZE)) > 0)
	{
		element_check(&res[fd], buf, read_count);
		if ((idx = ft_strchr_idx(res[fd], '\n')) >= 0)
			return (line_check(idx, line, &res[fd]));
		else if ((BUFF_SIZE > read_count) && idx < 0)
			return (final_line_check(ft_strlen(res[fd]), line, &res[fd]));
	}
	if (res[fd][0])
	{
		if ((idx = ft_strchr_idx(res[fd], '\n')) >= 0)
			return (line_check(idx, line, &res[fd]));
		return (final_line_check(ft_strlen(res[fd]), line, &res[fd]));
	}
	return (0);
}
