/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:28:33 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/21 18:35:36 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		check_and_stack_pipe(t_lem *anthill, char **str, int *i)
{
	int		tmp_i;

	tmp_i = *i;
	if (!(anthill->nb_pipe = check_pipe(anthill, str, tmp_i)))
	{
		while (anthill->nb_room--)
			free(anthill->room[anthill->nb_room].name);
		free(anthill->room);
		return (0);
	}
	if (!(anthill->pipe = (t_pipe*)malloc(sizeof(*(anthill->pipe))
	* anthill->nb_pipe)))
		return (0);
	*i = tmp_i;
	if (!(anthill->pipe = stack_pipe(anthill, *str, i)))
	{
		while (anthill->nb_room--)
			free(anthill->room[anthill->nb_room].name);
		free(anthill->room);
		free(anthill->pipe);
		return (0);
	}
	return (1);
}

int		check_and_stack_rooms(char *str, int *i, t_lem *anthill)
{
	int		tmp_i;

	if (str[*i] != '\n')
		return (0);
	tmp_i = ++(*i);
	if ((anthill->nb_room = check_rooms(str, tmp_i)) < 0)
		return (0);
	if (!(anthill->room = (t_room*)malloc(sizeof(*(anthill->room))
		* anthill->nb_room)))
		return (0);
	*i = tmp_i;
	if (!(create_room(anthill, str, i)))
	{
		free(anthill->room);
		return (0);
	}
	if (!check_same_name(anthill) || !check_same_coordinate(anthill) ||
	anthill->nb_room > 3000)
	{
		while (anthill->nb_room--)
			free(anthill->room[anthill->nb_room].name);
		free(anthill->room);
		return (0);
	}
	return (1);
}

int		parse_infos(char **str, t_lem *anthill)
{
	int		i;
	char	*tmp;

	i = 0;
	if ((*str)[i] != '\0')
	{
		if (!(tmp = ft_strdup(*str)))
			return (0);
		if (!remove_comments(str) || (*str)[i] == '\0' || !parse_digit(*str, &i)
		|| !check_and_stack_rooms(*str, &i, anthill) ||
		!check_and_stack_pipe(anthill, str, &i))
		{
			free(tmp);
			return (0);
		}
		anthill->nb_lem = ft_atoi(&(*str)[0]);
		if (!(add_comments(str, tmp)))
		{
			free(tmp);
			return (0);
		}
	}
	return (1);
}

int		read_parse(char **str)
{
	char	*tmp;
	int		ret;

	if (!(tmp = ft_strnew(1)))
		return (0);
	if ((ret = read(0, *str, 1)) <= 0)
	{
		free(tmp);
		return (0);
	}
	(*str)[ret] = '\0';
	if (ret > 0)
	{
		while ((ret = read(0, tmp, 1)) > 0)
		{
			tmp[ret] = '\0';
			if (!(*str = ft_strjoin_free(*str, tmp)))
				return (0);
		}
	}
	free(tmp);
	if (ret < 0)
		return (0);
	return (1);
}
