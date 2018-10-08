/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:00:27 by bgeorges          #+#    #+#             */
/*   Updated: 2018/06/23 14:03:34 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tab_cmp(int *tab_1, int len_1, int *tab_2, int len_2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (++i < len_1)
	{
		while (++j < len_2)
		{
			if (tab_1[i] == tab_2[j])
				return (0);
		}
		j = 0;
	}
	return (1);
}
