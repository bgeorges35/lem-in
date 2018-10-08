/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 18:54:49 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/17 02:35:56 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	check_start_end(int *ret, int *index, int start, int end)
{
	if (start)
	{
		*ret = 1;
		*index = 0;
	}
	else if (end)
	{
		*ret = 2;
		*index = 1;
	}
}

int		check_switch(char *str, int *i, int *index)
{
	static int			ret = 0;
	int					start;
	int					end;
	static int			tmp_index = 2;

	start = 0;
	end = 0;
	if (!is_switch(str, i, &start, &end))
		return (0);
	if ((start && ret != 2) || (end && ret != 1))
		tmp_index = *index;
	if (start || end)
		check_start_end(&ret, index, start, end);
	else
	{
		if (ret == 0)
			tmp_index = *index;
		*index = tmp_index;
		ret = 0;
	}
	return (1);
}

int		create_room(t_lem *anthill, char *str, int *i)
{
	int		index;
	int		count;
	int		tmp;

	index = 2;
	count = 0;
	if (!check_switch(str, i, &index))
		return (0);
	while ((index < anthill->nb_room || count < 2))
	{
		tmp = *i;
		is_name_room(str, i, 0);
		if (!(anthill->room[index].name = ft_strsub(str, tmp, *i - tmp)))
			return (0);
		anthill->room[index].x = ft_atoi(&str[(*i)++]);
		ft_isdigit_index(str, i);
		anthill->room[index].y = ft_atoi(&str[(*i)++]);
		if ((*i += ft_isdigit_index(str, i)) && index > 1)
			index++;
		else
			count++;
		if (!check_switch(str, i, &index))
			return (0);
	}
	return (1);
}

int		check_same_name(t_lem *anthill)
{
	int		i;
	int		j;

	j = 1;
	i = 0;
	while (i < anthill->nb_room)
	{
		while (j < anthill->nb_room)
		{
			if (!ft_strcmp(anthill->room[i].name,
			anthill->room[j].name) && j != i)
				return (0);
			j++;
		}
		i++;
		j = 1;
	}
	return (1);
}

int		check_same_coordinate(t_lem *anthill)
{
	int		i;
	int		j;

	j = 1;
	i = 0;
	while (i < anthill->nb_room)
	{
		while (j < anthill->nb_room)
		{
			if ((anthill->room[i].x == anthill->room[j].x)
			&& (anthill->room[i].y == anthill->room[j].y) && j != i)
				return (0);
			j++;
		}
		i++;
		j = 1;
	}
	return (1);
}
