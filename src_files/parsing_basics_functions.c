/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_basics_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:56:34 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/17 23:55:06 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		ft_isdigit_index(char *str, int *i)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i + 1] >= '0' && str[*i + 1] <= '9')
			(*i)++;
		else
			return (1);
	}
	if (str[*i] == '\0')
		return (1);
	while (str[*i] != '\0')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
		else
			return (1);
	}
	return (0);
}

int		is_new_line(char *str, int i)
{
	int	ret;

	ret = i;
	while (str[ret] != '\n' && str[ret] != '\0')
		ret++;
	return (ret);
}

int		is_space(char *str, int i)
{
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int		parse_digit(char *str, int *i)
{
	char	*tmp;
	int		len;
	int		ret;

	len = *i;
	ft_isdigit_index(str, &len);
	len -= *i;
	if (!(tmp = ft_strsub(str, *i, len)))
		return (0);
	if (!ft_is_integer(tmp))
	{
		free(tmp);
		return (0);
	}
	ret = ft_atoi(tmp);
	*i += len;
	free(tmp);
	return (1);
}
