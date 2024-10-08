/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:28:46 by gade-oli          #+#    #+#             */
/*   Updated: 2024/10/10 18:10:32 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ksort_range_in_b(t_list **stack_a, t_list **stack_b, unsigned int size)
{
	unsigned int	i;
	unsigned int	range;

	i = 0;
	range = ft_sqrt(size) * 1.4;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push(stack_a, stack_b, 'b', 1);
			if (*stack_a && (*stack_a)->index > i + range)
				rr(stack_a, stack_b, 1);
			else
				rotate(stack_b, 'b', 1);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			push(stack_a, stack_b, 'b', 1);
			i++;
		}
		else
			rotate(stack_a, 'a', 1);
	}
}

void	ksort_back_to_a(t_list **stack_a, t_list **stack_b, unsigned int size)
{
	int	rb_count;
	int	rrb_count;
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		rb_count = count_rotations(stack_b, i);
		rrb_count = i + 1 - rb_count;
		if (rb_count <= rrb_count)
		{
			while ((*stack_b)->index != (unsigned int) i)
				rotate(stack_b, 'b', 1);
		}
		else
		{
			while ((*stack_b)->index != (unsigned int) i)
				reverse_rotate(stack_b, 'b', 1);
		}
		push(stack_b, stack_a, 'a', 1);
		i--;
	}
}
