/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:54:45 by sapark            #+#    #+#             */
/*   Updated: 2019/05/16 17:14:59 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (*alst)
	{
		tmp = (*alst);
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = NULL;
		(*alst) = (*alst)->next;
	}
}
