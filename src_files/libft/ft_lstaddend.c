/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:12:25 by bgeorges          #+#    #+#             */
/*   Updated: 2018/06/15 12:12:32 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	if (new == NULL)
		return ;
	*alst = ft_lstend(*alst);
	new->prev = *alst;
	if (*alst != NULL)
		(*alst)->next = new;
	*alst = new;
}
