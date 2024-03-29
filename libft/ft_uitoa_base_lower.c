/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:33:42 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/21 20:01:35 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strleni(unsigned int n, int base)
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

static char		*ft_print_nbr(int len, char *str, unsigned int n, int base)
{
	while (len--)
	{
		str[len] = "0123456789abcdef"[n % base];
		n = n / base;
	}
	return (str);
}

char			*ft_uitoa_base_lower(unsigned int n, int base)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_strleni(n, base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str = ft_print_nbr(len, str, n, base);
	return (str);
}
