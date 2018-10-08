/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 21:53:42 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/17 22:22:06 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_integer(char *str)
{
	int		nb_len;
	int		i;
	int		neg;

	i = 0;
	nb_len = 0;
	neg = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	if (ft_str_isdigit(str))
		return (0);
	while (str[i] == '0')
		i++;
	while (str[i++] != '\0')
		nb_len++;
	if (nb_len - neg <= 10 && ft_atoll(str) <= INT_MAX &&
	ft_atoll(str) >= INT_MIN)
		return (1);
	return (0);
}
