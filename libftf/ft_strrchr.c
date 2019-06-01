/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:38:44 by sapark            #+#    #+#             */
/*   Updated: 2019/05/15 13:02:56 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		len;
	int		i;

	ptr = (char *)s;
	len = ft_strlen(ptr);
	i = len - 1;
	if (c == '\0')
		return (ptr + len);
	while (len > 0)
	{
		if (ptr[i] != c && i >= 0)
		{
			i--;
		}
		else
			return (ptr + i);
		len--;
	}
	return (NULL);
}
