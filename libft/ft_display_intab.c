/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_intab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:04:48 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/21 15:06:44 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_display_intab(int *tab, int len)
{
	int i;

	i = 0;
	while (len > i)
	{
		ft_printf("%d ", tab[i]);
		i++;
	}
	ft_printf("-> %d", i);
	ft_printf("\n");
}
