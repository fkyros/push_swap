/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:15:23 by gade-oli          #+#    #+#             */
/*   Updated: 2024/06/21 18:27:41 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	ft_printf("-----------------------\n");
	while (stack->below != NULL)
	{
		ft_printf("stack[%d] = %d\n", i, stack->content);
		stack = stack->below;
		i++;
	}
	ft_printf("stack[%d] = %d\n", i, stack->content);
	ft_printf("stack[%d] = NULL\n", i + 1);
}

void	free_stack(t_stack *stack)
{
	t_stack *aux;

	while (stack != NULL)
	{
		aux = stack->below;
		free(stack);
		stack = aux;
	}
}
