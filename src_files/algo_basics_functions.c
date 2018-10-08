/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_basics_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:29:51 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/19 01:19:05 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		init_way(t_lem *anthill)
{
	int	i;

	i = 0;
	if (!(anthill->way = (t_way*)malloc(sizeof(*(anthill->way))
	* anthill->nb_lem)))
		return (0);
	while (i < anthill->nb_lem)
	{
		anthill->way[i].i = 1;
		i++;
	}
	return (1);
}

int		is_pipe_unsed(int pipe, int *stack_pipe)
{
	int		i;

	i = 0;
	while (stack_pipe[i] != -1)
	{
		if (stack_pipe[i] == pipe)
			return (0);
		i--;
	}
	return (1);
}

int		is_multi_same_room(int cmp, int *way)
{
	int i;

	i = -1;
	while (way[i] != 0)
	{
		if (way[i] == cmp)
			return (0);
		i--;
	}
	if (cmp == 0)
		return (0);
	return (1);
}

int		find_len_way(int *way)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (way[i] != 0)
	{
		way--;
		len++;
	}
	return (len);
}

t_list	*add_way(int *way, int len)
{
	static t_list	*ways = NULL;

	if (!way && len)
		return (NULL);
	if (len)
	{
		if (!ways)
		{
			if (!(ways = ft_lstnew(way, len + 1)))
				return (0);
		}
		else
		{
			if (!(ft_lstadd(&ways, ft_lstnew(way, len + 1))))
				return (NULL);
		}
		free(way);
	}
	return (ways);
}
