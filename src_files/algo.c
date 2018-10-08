/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:10:23 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/21 16:11:40 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		lst_sorted(t_list *ways, t_list **new, int len)
{
	while (ways != NULL)
	{
		if (len == ways->content_size)
		{
			if (!ft_lstadd(new,
			ft_lstnew(ways->content, ways->content_size)))
				return (0);
		}
		ways = ways->next;
	}
	return (1);
}

t_list	*sort_lst(t_list *ways)
{
	t_list		*begin;
	t_list		*new;
	int			len;
	int			tmp;

	begin = ways;
	tmp = 0;
	new = NULL;
	while (!new || new->content_size != ft_lstlenmin(ways))
	{
		len = ft_lstlenmin(ways);
		while (ways != NULL)
		{
			if (len < ways->content_size && (tmp > ways->content_size || !tmp))
				len = ways->content_size;
			ways = ways->next;
		}
		tmp = len;
		ways = begin;
		if (!lst_sorted(ways, &new, len))
			return (NULL);
		ways = begin;
	}
	ft_free_lst(&ways);
	return (new);
}

int		check_save_combination(t_list *tmp, t_list *new)
{
	int		tmp_cnt;
	int		new_cnt;
	t_list	*ptr_new;
	t_list	*ptr_tmp;

	ptr_tmp = tmp;
	ptr_new = new;
	tmp_cnt = 0;
	new_cnt = 0;
	while (tmp)
	{
		tmp_cnt += tmp->content_size;
		tmp = tmp->next;
	}
	tmp = ptr_tmp;
	while (new)
	{
		new_cnt += new->content_size;
		new = new->next;
	}
	new = ptr_new;
	if (ft_lst_len(tmp) > ft_lst_len(new) && tmp_cnt < new_cnt)
		return (1);
	return (0);
}

int		add_way_lem(t_lem *anthill, t_list *way, int *i)
{
	t_list	*ptr_way;

	ptr_way = way;
	while (way)
	{
		if (!(anthill->way[*i].way = ft_intabdup(way->content,
		way->content_size)))
			return (1);
		anthill->way[*i].len = way->content_size;
		(*i)++;
		way = way->next;
	}
	way = ptr_way;
	return (0);
}

int		main_solver(t_lem *anthill, char *str)
{
	t_list	*ways;

	if (!stack_ways(anthill))
		return (0);
	if (!init_way(anthill))
		return (0);
	if (!(ways = add_way(0, 0)))
		return (0);
	ft_putstr(str);
	if (!(ways = sort_lst(ways)))
		return (0);
	if (!algo_solver(anthill, ways))
		return (0);
	ft_free_lst(&ways);
	return (1);
}
