/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimby.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 00:17:16 by sapark            #+#    #+#             */
/*   Updated: 2019/07/31 01:00:43 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimby(char const *s, char c)
{
	unsigned int	len;
	unsigned int	i;

	while (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == c)
		i++;
	while (i < len && (s[len - 1] == ' '
		|| s[len - 1] == '\n' || s[len - 1] == '\t' || s[len - 1] == c))
		len--;
	return (ft_strsub(s, i, len - i));
}
