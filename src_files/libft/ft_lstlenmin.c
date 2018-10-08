/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlenmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:52:21 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/14 21:54:49 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlenmin(t_list *lst)
{
	t_list		*begin;
	int			min;

	begin = lst;
	min = lst->content_size;
	while (lst != NULL)
	{
		if (min > lst->content_size)
			min = lst->content_size;
		lst = lst->next;
	}
	lst = begin;
	return (min);
}
