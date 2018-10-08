/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_lst_intab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:10:47 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/21 15:11:18 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	display_lst_inttab(t_list *ways)
{
	int		i;
	t_list	*begin;

	i = 0;
	begin = ways;
	while (ways)
	{
		ft_display_intab((int*)ways->content, (int)ways->content_size);
		ways = ways->next;
		if (ways == NULL)
			break ;
		i++;
	}
	ways = begin;
	ft_printf("%c", 10);
}
