/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:50:42 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/29 16:16:40 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//in-place sort for 3 items in the stack
void	small_sort(t_list **stack_a)
{
	t_list		*aux;
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	print_stack(stack_a);
	if (is_sorted(stack_a))
		return ;
	aux = *(stack_a);
	a = aux->index;
	b = aux->next->index;
	c = aux->next->next->index;
	if (a > b && a < c)
		swap(stack_a, 'a', 1);
	else if (a > b && a > c)
		reverse_rotate(stack_a, 'a', 1);
	else if (b > a && b > c)
		reverse_rotate(stack_a, 'a', 1);
	else if (b > a && b > c)
		swap(stack_a, 'a', 1);
	small_sort(stack_a);
}

/**
 * optimized small cases for required efficiency
 */
//void	insertion_sort(t_list **stack_a, t_list **stack_b, int size)


/**
 * algorithm chooser given the items on the list
 */
void	sort_stack(t_list **stack_a, t_list **stack_b, unsigned int size)
{
	if (size == 2)
		swap(stack_a, 'a', 1);
	else if (size == 3)
		small_sort(stack_a);
	//else if (size < 25)
	//	insertion_sort();
	else
	{
		ksort_range_in_b(stack_a, stack_b, size);
		ksort_back_to_a(stack_a, stack_b, size);
	}
}
