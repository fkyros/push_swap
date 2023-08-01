/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:35:33 by gade-oli          #+#    #+#             */
/*   Updated: 2023/08/01 14:20:31 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * given the first element of the stack, prints through the stdout the whole stack
 */
void	print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		ft_putstr_fd(stack->content, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		stack = stack->next;
	}
}

int main()
{
	t_stack	**stack;
	t_stack *stacked;
	int i;

	stack = malloc(sizeof(t_stack *) * 5);
	i = 0;
	while (i < 5)
	{
		stacked = ft_stnew(&i);
		if (!i)
			*stack = stacked;
		else
			ft_stpush(stack, stacked);
		i++;
	}
	print_stack(*stack);
	return 0;
}
