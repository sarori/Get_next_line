/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:48:22 by sapark            #+#    #+#             */
/*   Updated: 2019/05/17 21:19:25 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*ptr1;
	const char	*ptr2;

	if (!dst && !src)
		return (NULL);
	i = 0;
	ptr1 = (char *)dst;
	ptr2 = (const char *)src;
	while (n > 0)
	{
		ptr1[i] = ptr2[i];
		n--;
		i++;
	}
	return (dst);
}
