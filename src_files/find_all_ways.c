/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:00:48 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/20 06:09:23 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		add_room_way(t_lem *anthill, int *way, int *stack_pipe)
{
	int	i;
	int	cmp;

	i = 0;
	while (i < anthill->nb_pipe)
	{
		if ((anthill->pipe[i].r_1 == *(way - 1)
			|| anthill->pipe[i].r_2 == *(way - 1)))
		{
			if (anthill->pipe[i].r_1 == *(way - 1))
				cmp = anthill->pipe[i].r_2;
			else
				cmp = anthill->pipe[i].r_1;
			if (is_pipe_unsed(i, stack_pipe) && is_multi_same_room(cmp, way))
			{
				*(stack_pipe + 1) = i;
				*(way++) = cmp;
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int		recursive_stack_way(t_lem *anthill, int *way, int *stack_pipe)
{
	int		len;
	int		ret;

	len = 0;
	while (*(way - 1) != 0)
	{
		if (*(way - 1) == 1)
		{
			len = find_len_way(--way);
			if (!add_way(ft_intabdup((way - len), len + 1), len))
				return (-1);
			return (2);
		}
		else
		{
			if (!add_room_way(anthill, way, stack_pipe))
				return (2);
			if ((ret = recursive_stack_way(anthill, way + 1, stack_pipe + 1))
			< 0)
				return (ret);
			else if (ret == 2)
				stack_pipe = stack_pipe + 1;
		}
	}
	return (0);
}

int		start_recursive(t_lem *anthill, int *way, int *stack_pipe)
{
	int		i;
	int		*ptr_way;
	int		*ptr_stack_pipe;

	ptr_stack_pipe = stack_pipe;
	ptr_way = way;
	i = 0;
	while (i < anthill->nb_pipe)
	{
		if (anthill->pipe[i].r_1 == 0 || anthill->pipe[i].r_2 == 0)
		{
			way = ptr_way;
			stack_pipe = ptr_stack_pipe;
			if (anthill->pipe[i].r_1 == 0)
				(*++way) = anthill->pipe[i].r_2;
			else
				(*++way) = anthill->pipe[i].r_1;
			*stack_pipe = i;
			if (recursive_stack_way(anthill, way + 1, stack_pipe) < 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int		stack_ways(t_lem *anthill)
{
	int		*way;
	int		*stack_pipe;
	int		*ptr_stack_pipe;
	int		*ptr_way;
	int		res;

	if (!(way = (int*)malloc(sizeof(int) * anthill->nb_room)))
		return (0);
	if (!(stack_pipe = (int*)malloc(sizeof(int) * (anthill->nb_pipe + 1))))
		return (0);
	*way = 0;
	ptr_stack_pipe = stack_pipe;
	ptr_way = way;
	if (anthill->nb_pipe > 1)
		*(stack_pipe++) = -1;
	res = start_recursive(anthill, way, stack_pipe);
	free(ptr_way);
	free(ptr_stack_pipe);
	return (res);
}
