/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustoa_base_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:32:13 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/21 19:40:00 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strleni(unsigned short int n, int base)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static char	*ft_print_nbr(int len, char *str,
					unsigned short int n, int base)
{
	while (len--)
	{
		str[len] = "0123456789ABCDEF"[n % base];
		n = n / base;
	}
	return (str);
}

char		*ft_ustoa_base_lower(unsigned short int n, int base)
{
	char	*str;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_strleni(n, base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str = ft_print_nbr(len, str, n, base);
	return (str);
}
