/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:39:52 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/20 21:05:01 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	count_rotations(t_list **stack, unsigned int index)
{
	int	res;
	int	flag;
	t_list	*original;

	res = 0;
	flag = 0;
	if (!*stack)
		return (0);
	original = *stack;
	while (*stack && (*stack)->next && !flag)
	{
		if ((*stack)->index == index)
			flag = 1;
		else
			res++;
		*stack = (*stack)->next;
	}
	*stack = original;
	return (res);
}

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
