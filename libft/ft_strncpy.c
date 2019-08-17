/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:51:42 by sapark            #+#    #+#             */
/*   Updated: 2019/07/29 20:47:22 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int	n;
	int				i;

	i = 0;
	n = ft_strlen(src);
	if (n < len)
	{
		while (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		while (len - i > 0)
		{
			dst[i] = '\0';
			i++;
		}
	}
	else
		while (len-- > 0)
		{
			dst[i] = src[i];
			i++;
		}
	return (dst);
}
