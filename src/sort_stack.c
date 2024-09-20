/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:28:46 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/20 20:54:43 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * optimized small cases for required efficiency
 */
void	small_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		swap(stack_a, 'a', 1);
	(void)stack_b;
	/*if (size < 7)
		simple_sort();
	if (size < 12)*/
}

/*
 * ir por chunks. 
 *
 */
void	ksort_range_in_b(t_list **stack_a, t_list **stack_b, unsigned int size)
{
	unsigned int	i;
	unsigned int	range;

	print_stack(stack_a);
	i = 0;
	range = ft_sqrt(size) * 1.4;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b', 1);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			push(stack_a, stack_b, 'b');
			i++;
		}
		else
			rotate(stack_a, 'a', 1);
	}
	printf("FIN 1: stack_a vacio\n");
}

void	ksort_back_to_a(t_list **stack_a, t_list **stack_b, unsigned int size)
{
	int	rb_count;
	int	rrb_count;
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		printf("STACK_A:\n");
		print_stack(stack_a);
		printf("STACK_B:\n");
		print_stack(stack_b);

		rb_count = count_rotations(stack_b, i);
		rrb_count = i - rb_count;
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
		push(stack_b, stack_a, 'a');
		i--;
	}
}
