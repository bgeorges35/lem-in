/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 20:58:24 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/17 22:37:08 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		skip_comment(char **str, int *i)
{
	int		tmp;
	char	*new1;
	char	*new2;

	if (!(new1 = ft_strndup(*str, *i)))
		return (0);
	tmp = *i;
	*i = is_new_line(*str, *i);
	if ((*str)[*i] == '\n')
		(*i)++;
	if (!(new2 = ft_strdup(&((*str)[*i]))))
		return (0);
	free(*str);
	if (!(*str = ft_strjoin_free_both(new1, new2)))
		return (0);
	*i = tmp;
	return (1);
}

int		remove_comments(char **str)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	while ((*str)[i])
		if ((*str)[i] == '#' && !ft_strnequ("##start\n", &((*str)[i]), 8)
		&& !ft_strnequ("##end\n", &((*str)[i]), 6))
		{
			if (!skip_comment(str, &i))
				return (0);
		}
		else
		{
			start += ft_strnequ("##start\n", &((*str)[i]), 8);
			end += ft_strnequ("##end\n", &((*str)[i]), 6);
			i = is_new_line(*str, i);
			if ((*str)[i] == '\n')
				i++;
		}
	if (start != 1 || end != 1)
		return (0);
	return (1);
}

void	is_equality(char **str, char *tmp, int *i_tmp, int *i_str)
{
	if (ft_strnequ("\n##start\n", &(*str)[*i_str], 9) !=
	ft_strnequ("\n##start\n", &tmp[*i_tmp], 9)
	|| (!i_str && ft_strnequ("##start\n", &(*str)[*i_str], 8) !=
	ft_strnequ("##start\n", &tmp[*i_tmp], 8))
	|| (!i_str && ft_strnequ("##end\n", &(*str)[*i_str], 6) !=
	ft_strnequ("##end\n", &tmp[*i_tmp], 6))
	|| ft_strnequ("\n##end\n", &(*str)[*i_str], 7) !=
	ft_strnequ("\n##end\n", &tmp[*i_tmp], 7))
	{
		if (tmp[*i_tmp] == '\n')
			(*i_tmp)++;
		*i_tmp = is_new_line(tmp, *i_tmp);
	}
	else
	{
		(*i_tmp)++;
		(*i_str)++;
	}
}

int		add_comments(char **str, char *tmp)
{
	int		i_str;
	int		i_tmp;

	i_str = 0;
	i_tmp = 0;
	while ((*str)[i_str])
		if ((*str)[i_str] == tmp[i_tmp])
			is_equality(str, tmp, &i_tmp, &i_str);
		else if (tmp[i_tmp] == '#')
		{
			if ((i_tmp = is_new_line(tmp, i_tmp)) && tmp[i_tmp] == '\n')
				i_tmp++;
		}
		else
			break ;
	if (tmp[i_tmp] == '\n')
		i_tmp++;
	while (tmp[i_tmp] == '#')
		if ((i_tmp = is_new_line(tmp, i_tmp)) && tmp[i_tmp] == '\n')
			i_tmp++;
	free(*str);
	if (!(*str = ft_strsub_free(tmp, 0, i_tmp)))
		return (0);
	return (1);
}
