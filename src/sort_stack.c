/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:28:46 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/10 20:17:48 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 * ir por chunks. 
 *
 */
void	ksort_range(t_list **stack_a, t_list *stack_b, int original_size)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(original_size) * 14/10;
	while (stack_a->next)
	{
		if (stack_a->content->index < i)
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b', 1);
			i++;
		}
		else if (stack_a->content->index < i + range)
		{
			push(stack_a, stack_b, 'b');
			i++;
		}
		else
			rotate(stack_a, 'a', 1);
	}
}

void	k_sort2(t_list **stack_a, t_list **stack_b, int original_size)
{
	int	rb_count;
	int	rrb_count;

	while (original_size - 1 >= 0)
	{
		rb_count = count_r(stack_b->, original_size - 1);
		rrb_count = (original_size + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->s_index != length - 1)
				rotate(stack_b, 'b', true);
			push(stack_a, stack_b, 'a', true);
			length--;
		}
		else
		{
			while (stack_b->head->s_index != length - 1)
				reverse_rotate(stack_b, 'b', true);
			push(stack_a, stack_b, 'a', true);
			length--;
		}
	}
}

//void	ksort_back_to_a
