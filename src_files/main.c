/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:10:21 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/21 16:20:01 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	error(t_lem *anthill, char *str)
{
	ft_putstr("ERROR\n");
	free(str);
	free(anthill);
}

void	free_anthill(t_lem *anthill)
{
	while (anthill->nb_room--)
		free(anthill->room[anthill->nb_room].name);
	free(anthill->way);
	free(anthill->room);
	free(anthill->pipe);
	free(anthill);
}

int		main(void)
{
	char	*str;
	t_lem	*anthill;

	anthill = (t_lem*)malloc(sizeof(*anthill));
	if (!(str = ft_strnew(1)))
		return (0);
	if (!read_parse(&str) || !parse_infos(&str, anthill))
	{
		error(anthill, str);
		return (0);
	}
	if (!main_solver(anthill, str))
	{
		free_anthill(anthill);
		free(str);
		ft_putstr("ERROR\n");
		return (0);
	}
	free(str);
	free_anthill(anthill);
	return (1);
}
