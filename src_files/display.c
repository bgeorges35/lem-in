/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:23:19 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/21 15:11:04 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	aff_result(t_lem *anthill, int **tmp, int *i_tmp, int i)
{
	(*tmp)[*i_tmp] = anthill->way[i].way[anthill->way[i].i++];
	if (*i_tmp)
		ft_putchar(' ');
	ft_printf("%c%d-%s", 'L', i + 1, anthill->room[(*tmp)[(*i_tmp)++]].name);
	if (anthill->way[i].i == anthill->way[i].len)
		anthill->way[i].i++;
}

int		is_finish(t_lem *anthill, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (anthill->way[i].i >= anthill->way[i].len)
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_display_solve(t_lem *anthill, int len)
{
	int		i;
	int		i_tmp;
	int		*tmp;
	int		lem;

	lem = 1;
	while (!is_finish(anthill, len))
	{
		i = -1;
		i_tmp = 0;
		if (!(tmp = (int*)malloc(sizeof(int) * len)))
			return (0);
		while (++i < len)
		{
			if (anthill->way[i].i < anthill->way[i].len &&
			(!i_tmp || anthill->way[i].way[anthill->way[i].i] == 1 ||
			!ft_cmpintab(anthill->way[i].way[anthill->way[i].i], tmp, i_tmp)))
				aff_result(anthill, &tmp, &i_tmp, i);
		}
		ft_putchar(10);
		free(tmp);
	}
	return (1);
}
