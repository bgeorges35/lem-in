/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:03:02 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/12 16:18:16 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_len(t_list *lst)
{
	t_list	*begin;
	int		len;

	len = 0;
	begin = lst;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	lst = begin;
	return (len);
}
