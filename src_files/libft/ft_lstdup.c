/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:30:50 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/14 20:44:13 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstdup(t_list *lst)
{
	t_list	*lst_ptr;
	t_list	*new;

	lst_ptr = lst;
	new = NULL;
	while (lst)
	{
		ft_lstadd(&new, ft_lstnew(lst->content, lst->content_size));
		lst = lst->next;
	}
	lst = lst_ptr;
	return (new);
}
