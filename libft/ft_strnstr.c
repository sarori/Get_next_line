/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:12:27 by sapark            #+#    #+#             */
/*   Updated: 2019/05/16 23:15:59 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		size;

	i = 0;
	j = 0;
	size = ft_strlen(needle);
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] != '\0' && len >= i + size)
	{
		if (haystack[i] == needle[0])
		{
			j = 1;
			while (needle[j] != '\0' && haystack[i + j] != '\0'
					&& haystack[i + j] == needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
		}
		++i;
	}
	return (NULL);
}
