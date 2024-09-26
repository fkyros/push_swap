/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:50:42 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/26 19:33:02 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * optimized small cases for required efficiency
 */
void	small_sort(t_list **stack_a, t_list **stack_b, int size);

void	sort_stack(t_list **stack_a, t_list **stack_b, unsigned int size)
{
	if (size == 2)
		swap(stack_a, 'a', 1);
	else
	{
		ksort_range_in_b(stack_a, stack_b, size);
		ksort_back_to_a(stack_a, stack_b, size);
	}
}

//void	insertion_sort(t_list **stack_a, t_list **stack_b, int size)
