/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:50:34 by sapark            #+#    #+#             */
/*   Updated: 2019/05/16 17:18:45 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	len1;
	unsigned int	len2;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (n-- > 0)
	{
		if (*s1 != *s2)
			return (0);
		else
		{
			s1++;
			s2++;
		}
	}
	return (1);
}
