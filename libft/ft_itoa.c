/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 22:16:53 by sapark            #+#    #+#             */
/*   Updated: 2019/05/17 00:00:31 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*res;
	int				number;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	number = n;
	size = (unsigned int)ft_digit((n < 0) ? -1 * number : number);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1 + ((n < 0) ? 1 : 0)))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(res, "-2147483648"));
	number = ft_abs(n);
	if (n < 0 && (res[i] = '-'))
		size++;
	i = size - 1;
	while (number >= 10)
	{
		res[i--] = (char)(number % 10 + '0');
		number = number / 10;
	}
	res[i] = (char)(number % 10 + '0');
	res[size] = '\0';
	return (res);
}
