/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:09 by sapark            #+#    #+#             */
/*   Updated: 2019/05/17 17:36:24 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_number_length(int n)
{
	if (n < 10)
		return (1);
	else
		return (ft_number_length(n % 10) + ft_number_length(n / 10));
}
