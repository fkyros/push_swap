/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:36:28 by gade-oli          #+#    #+#             */
/*   Updated: 2024/08/05 21:55:20 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*iter;

	iter = *stack;
	while (iter->next)
	{
		if (!(iter->content < iter->next->content))
			return (0);
		iter = iter->next;
	}
	return (1);
}
