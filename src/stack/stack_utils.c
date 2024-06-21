/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:15:23 by gade-oli          #+#    #+#             */
/*   Updated: 2024/06/21 16:30:40 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	printf("-----------------------\n");
	while (stack->below != NULL)
	{
		printf("stack[%d] = %d\n", i, stack->content);
		stack = stack->below;
		i++;
	}
	printf("stack[%d] = %d\n", i, stack->content);
	printf("stack[%d] = NULL\n", i + 1);
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
