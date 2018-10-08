/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intabdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:26:36 by bgeorges          #+#    #+#             */
/*   Updated: 2018/06/18 22:21:56 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intabdup(int *tab, int len)
{
	int *new;
	int i;

	i = 0;
	if (!(new = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	while (len > i)
	{
		new[i] = tab[i];
		i++;
	}
	return (new);
}
