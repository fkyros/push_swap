/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:12:01 by gade-oli          #+#    #+#             */
/*   Updated: 2023/08/01 12:29:49 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * swaps the first two elements at the top of stack a
 */
int	sa(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_a)
		return (-1);
	first = ft_stpeek(stack_a);
	if (!first)
		return (-1);
	ft_stpop(stack_a);
	second = ft_stpeek(stack_a);
	if (!second)
		return (-1);
	ft_stpop(stack_a);
	ft_stpush(stack_a, first);
	ft_stpush(stack_a, second);
	ft_putstr_fd(STDOUT_FILENO, "sa\n");
	return (0);
}
