/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 22:13:32 by sapark            #+#    #+#             */
/*   Updated: 2019/05/15 13:34:50 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 != len2)
		return (0);
	while (len1-- && len2--)
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
