/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:53:46 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/18 00:27:22 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		is_pipe_syntax(t_lem *anthill, char *str, int *i)
{
	int		tmp_i;
	char	*tmp;

	tmp_i = *i;
	while (str[*i] != '-' && str[*i] != '\n' && str[*i] != '\0')
		(*i)++;
	if (!(tmp = ft_strsub(str, tmp_i, *i - tmp_i)))
		return (-1);
	tmp_i = 0;
	while (anthill->nb_room > tmp_i)
	{
		if (!ft_strcmp(tmp, anthill->room[tmp_i].name))
			break ;
		tmp_i++;
	}
	free(tmp);
	if (tmp_i == anthill->nb_room)
		return (-1);
	return (tmp_i);
}

int		is_pipe(t_lem *anthill, char *str, int *i)
{
	int		boolean;

	boolean = 0;
	if (str[*i] == '\n')
		return (0);
	while (str[*i] != '\n' && str[*i] != '\0')
	{
		if ((is_pipe_syntax(anthill, str, i)) < 0)
			return (0);
		if (str[*i] == '-' && boolean == 0)
		{
			boolean++;
			(*i)++;
		}
		else if ((str[*i] != '\n' && str[*i] != '\0'))
			return (0);
	}
	return (1);
}

int		remove_line(char **str, int *i)
{
	if ((*str)[*i] == '\n')
		(*i)--;
	while (*i != 0 && (*str)[*i] != '\n')
		(*i)--;
	if (*i)
	{
		if (!(*str = ft_strsub_free(*str, 0, *i)))
			return (0);
	}
	return (1);
}

int		check_pipe(t_lem *anthill, char **str, int i)
{
	int		nb_pipe;

	nb_pipe = 0;
	while ((*str)[i] != '\0')
	{
		if (!is_pipe(anthill, *str, &i))
		{
			if (!remove_line(str, &i))
				return (0);
			break ;
		}
		nb_pipe++;
		if ((*str)[i] == '\n')
			i++;
		else if ((*str)[i] != '\0')
			return (0);
	}
	return (nb_pipe);
}
