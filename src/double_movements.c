/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:22:19 by gade-oli          #+#    #+#             */
/*   Updated: 2024/08/20 18:14:13 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ss(t_stack **stack_a, t_stack **b)
{
	swap(stack_a, 'a', 0);
	swap(stack_b, 'b', 0);
	write(STDOUT_FILENO, "ss\n", 3);
}

void	rr(t_stack **stack_a, t_stack **b)
{
	rotate(stack_a, 'a', 0);
	rotate(stack_b, 'b', 0);
	write(STDOUT_FILENO, "rr\n", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, 'a', 0);
	reverse_rotate(stack_b, 'b', 0);
	write(STDOUT_FILENO, "rrr\n", 4);
}
