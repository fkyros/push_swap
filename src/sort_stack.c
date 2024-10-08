/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:50:42 by gade-oli          #+#    #+#             */
/*   Updated: 2024/10/08 16:36:03 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 * in-place sort for just three items in the stack
 * goal: max three moves for three elements
 */
void	small_sort(t_list **stack_a)
{
	t_list			*aux;
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	if (is_sorted(stack_a))
		return ;
	aux = *(stack_a);
	a = aux->index;
	b = aux->next->index;
	c = aux->next->next->index;
	if (a > b && a > c)
		rotate(stack_a, 'a', 1);
	else if (a > b && a < c)
		swap(stack_a, 'a', 1);
	else if (b > a && b > c)
		reverse_rotate(stack_a, 'a', 1);
	else if (b > a && b > c)
		swap(stack_a, 'a', 1);
	small_sort(stack_a);
}

/**
 * optimized small cases for required efficiency
 * goal: max twelve moves for five elements
 */
void	medium_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	i;

	i = 0;
	while (i < (size - 3))
	{
		if ((*stack_a)->index >= 3)
		{
			push(stack_a, stack_b, 'b');
			i++;
		}
		else
			rotate(stack_a, 'a', 1);
	}
	if (!is_sorted(stack_a))
		small_sort(stack_a);
	if ((*stack_b)->index == 4)
		swap(stack_b, 'b', 1);
	while (ft_lstsize(*stack_b) != 0)
	{
		push(stack_b, stack_a, 'a');
		rotate(stack_a, 'a', 1);
	}
}

/**
 * algorithm chooser given the items on the list
 */
void	sort_stack(t_list **stack_a, t_list **stack_b, unsigned int size)
{
	if (size == 2)
		swap(stack_a, 'a', 1);
	else if (size == 3)
		small_sort(stack_a);
	else if (size <= 10)
		medium_sort(stack_a, stack_b, size);
	else
	{
		ksort_range_in_b(stack_a, stack_b, size);
		ksort_back_to_a(stack_a, stack_b, size);
	}
}
