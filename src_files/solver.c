/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 22:13:42 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/21 18:05:52 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		compare_combination(t_list **new, int *tab, int i_tab)
{
	t_list	*new_ptr;

	new_ptr = *new;
	while ((*new)->next && ft_tab_cmp(tab, i_tab - 1,
	(*new)->content, (*new)->content_size - 1))
		*new = (*new)->next;
	if (ft_tab_cmp(tab, i_tab - 1, (*new)->content, (*new)->content_size - 1))
	{
		*new = new_ptr;
		if (!(ft_lstadd(new, ft_lstnew(tab, i_tab))))
			return (0);
		return (1);
	}
	else
		*new = new_ptr;
	return (1);
}

t_list	*find_combination(t_list *ways, int lem)
{
	t_list	*new;
	t_list	*ways_ptr;
	int		*tab;
	int		i_tab;

	ways_ptr = ways;
	if (!(new = ft_lstnew(ways->content, ways->content_size)))
		return (NULL);
	new->next = NULL;
	while (ways->next && lem > ft_lst_len(new))
	{
		ways = ways->next;
		if (!(tab = ft_intabdup(ways->content, ways->content_size)))
			return (NULL);
		i_tab = ways->content_size;
		if (!compare_combination(&new, tab, i_tab))
			return (NULL);
		free(tab);
	}
	ways = ways_ptr;
	return (new);
}

int		search_way(t_lem *anthill, t_list *ways, t_list *tmp, t_list **new)
{
	while (ways)
	{
		if (!(tmp = find_combination(ways, anthill->nb_lem)))
			return (0);
		if (!*new || check_save_combination(tmp, *new))
		{
			if (*new)
				ft_free_lst(new);
			if (!(*new = ft_lstdup(tmp)))
				return (0);
		}
		ft_free_lst(&tmp);
		ways = ways->next;
	}
	return (1);
}

int		algo_solver(t_lem *anthill, t_list *ways)
{
	t_list	*new;
	t_list	*tmp;
	t_list	*ptr_ways;
	int		i;

	new = NULL;
	tmp = NULL;
	ptr_ways = ways;
	i = 0;
	while (anthill->nb_lem > 0)
	{
		if (!search_way(anthill, ways, tmp, &new))
			return (0);
		anthill->nb_lem -= ft_lst_len(new);
		if (add_way_lem(anthill, new, &i))
			return (0);
		ft_free_lst(&new);
		ways = ptr_ways;
	}
	ft_putchar('\n');
	if (!(ft_display_solve(anthill, i)))
		return (0);
	while (i)
		free(anthill->way[--i].way);
	return (1);
}
