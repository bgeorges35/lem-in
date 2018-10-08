/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:01:43 by bgeorges          #+#    #+#             */
/*   Updated: 2018/04/25 18:01:52 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min_tab(int *tab, int len)
{
	int i;
	int res;

	i = 0;
	res = tab[i];
	while (len > i)
	{
		if (tab[i] < res)
			res = tab[i];
		i++;
	}
	return (res);
}
