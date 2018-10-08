/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:52:53 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/19 03:45:15 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		is_switch(char *str, int *i, int *start, int *end)
{
	char	*tmp;
	int		len;

	if (str[*i] == '#' && str[*i + 1] == '#')
	{
		len = is_new_line(str, *i) - *i;
		if (!(tmp = ft_strsub(str, *i, len + 1)))
			return (0);
		if (str[*i + len] != '\n')
			return (0);
		*i += len + 1;
		if (!ft_strcmp(tmp, "##start\n"))
			(*start)++;
		if (!ft_strcmp(tmp, "##end\n"))
			(*end)++;
		free(tmp);
	}
	return (1);
}

int		is_name_room(char *str, int *i, int tmp_index)
{
	if (str[*i] == 'L')
		return (0);
	while (str[*i] > 33 && str[*i] < 127)
		(*i)++;
	if (str[*i] != ' ')
	{
		*i = tmp_index;
		return (0);
	}
	return (1);
}

int		is_coordinate_room(char *str, int *i, int tmp_index)
{
	int		nb;

	nb = 0;
	while (str[*i] != '\n' && str[*i] != '\0')
	{
		if (!parse_digit(str, i))
			return (0);
		if (str[*i] == ' ' && !nb)
		{
			(*i)++;
			nb++;
		}
		else if (str[*i] == '\n' && nb == 1)
			return (1);
		else
		{
			*i = tmp_index;
			return (0);
		}
	}
	return (0);
}

int		is_room(char *str, int *i)
{
	int		boolean;
	int		tmp_index;

	boolean = 0;
	tmp_index = *i;
	if (!is_name_room(str, i, tmp_index))
		return (0);
	(*i)++;
	if (!is_coordinate_room(str, i, tmp_index))
		return (0);
	if (str[*i] != '\n')
		return (0);
	(*i)++;
	return (1);
}

int		check_rooms(char *str, int i)
{
	int		nb_room;
	int		end;
	int		start;

	nb_room = 0;
	start = 0;
	end = 0;
	while (str[i] != '\0')
	{
		if (!(is_switch(str, &i, &start, &end)))
			return (-1);
		if (!is_room(str, &i))
			break ;
		nb_room++;
	}
	if (start == 1 && end == 1)
		return (nb_room);
	return (-1);
}
