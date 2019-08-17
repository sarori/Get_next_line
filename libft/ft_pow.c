/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:23:08 by sapark            #+#    #+#             */
/*   Updated: 2019/07/31 16:23:22 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int base, int times)
{
	if (times == 0)
		return (1);
	else if (times == 1)
		return (base);
	else
		return (ft_pow(base, times - 1) * base);
}
