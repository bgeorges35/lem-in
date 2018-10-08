/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmpint_intab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 17:57:53 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/10 15:35:37 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cmpintab(int cmp, int *tab, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (cmp == tab[i])
			return (1);
		i++;
	}
	return (0);
}
