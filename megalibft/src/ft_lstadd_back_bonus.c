/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:53:29 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/20 18:10:34 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*it;

	it = *lst;
	if (!it && new)
	{
		*lst = new;
		new->next = NULL;
	}
	else if (it && new)
	{
		while (it->next)
			it = it->next;
		it->next = new;
		new->next = NULL;
	}
}
