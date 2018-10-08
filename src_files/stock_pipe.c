/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 18:57:03 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/17 02:35:55 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		stack_pipe1(t_lem *anthill, char *str, int *i, int nb_pipe)
{
	char	*tmp;
	int		tmp_i;

	tmp_i = *i;
	while (str[*i] != '-')
		(*i)++;
	anthill->pipe[nb_pipe].r_1 = 0;
	if (!(tmp = ft_strsub(str, tmp_i, *i - tmp_i)))
		return (0);
	while (ft_strcmp(tmp, anthill->room[anthill->pipe[nb_pipe].r_1].name))
		anthill->pipe[nb_pipe].r_1++;
	free(tmp);
	(*i)++;
	return (1);
}

int		stack_pipe2(t_lem *anthill, char *str, int *i, int nb_pipe)
{
	char	*tmp;
	int		tmp_i;

	tmp_i = *i;
	while (str[*i] != '\n' && str[*i] != '\0')
		(*i)++;
	anthill->pipe[nb_pipe].r_2 = 0;
	if (!(tmp = ft_strsub(str, tmp_i, *i - tmp_i)))
		return (0);
	while (ft_strcmp(tmp, anthill->room[anthill->pipe[nb_pipe].r_2].name))
		anthill->pipe[nb_pipe].r_2++;
	free(tmp);
	if (str[*i] == '\n')
		(*i)++;
	return (1);
}

t_pipe	*stack_pipe(t_lem *anthill, char *str, int *i)
{
	int		nb_pipe;

	nb_pipe = 0;
	while (anthill->nb_pipe > nb_pipe)
	{
		if (!stack_pipe1(anthill, str, i, nb_pipe))
			return (NULL);
		if (!stack_pipe2(anthill, str, i, nb_pipe))
			return (NULL);
		nb_pipe++;
	}
	return (anthill->pipe);
}
