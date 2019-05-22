/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 22:32:29 by sapark            #+#    #+#             */
/*   Updated: 2019/05/21 01:07:25 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> //open함수 only
#include <stdio.h>

char*	get_element(char *buf)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (NULL);
	while (buf[i] ! = '\n')
	{
		res[i] = buf[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	int			read_count;
	static char	*buf;
	char		*tmp;

	i = 0;
	read_count = read(fd, buf, BUFF_SIZE - 1);
	if (!(buf = get_element(buf)))
		return (-1);

	if(fd > 0)
	{
		while (!read_count)
		{
			ft_strcpy(tmp, get_element(buf));
			free(tmp);
			i++;
			read_count--;
		}
		buf[read_count] = '\0';

	}

	if (fd == -1)
		return (-1);
}
char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	len1;
	unsigned int	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	res[len1 + len2] = '\0';
	return (res);
}

int main()
{
	int			fd;
	char		*line;

	fd = open("tests/some_lines.txt", O_RDONLY);
	while (get_next_line(fd, &line))
		printf("%s", line);
	if ((fd = open("/tests/some_lines.txt", O_RDONLY) == -1))
		write(1, "fail\n", 5);
	return (0);
}
