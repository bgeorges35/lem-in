/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:04:03 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/21 18:04:19 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_lst(t_list **ways)
{
	t_list *next;

	while (*ways)
	{
		next = (*ways)->next;
		free((*ways)->content);
		free(*ways);
		*ways = next;
	}
}
