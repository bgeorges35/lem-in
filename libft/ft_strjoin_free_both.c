/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_both.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:23:07 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/14 20:45:51 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_both(char *tmp, char *buff)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(buff) + 1))))
	{
		ft_strdel(&buff);
		return (NULL);
	}
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
	}
	while (buff[j])
	{
		str[i + j] = buff[j];
		j++;
	}
	str[i + j] = 0;
	ft_strdel(&tmp);
	ft_strdel(&buff);
	return (str);
}
