/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:46:48 by gade-oli          #+#    #+#             */
/*   Updated: 2024/06/06 20:03:02 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*stack_new(void *content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->below = NULL;
	return (new);
}

int size(t_stack *stack)
{
	int	res;

	res = 0;
	while (stack != NULL)
	{
		res++;
		stack = stack->below;
	}
	return (res);
}

t_stack	*push(void *content, t_stack *stack)
{
	t_stack	*new;

	new = stack_new(content);
	if (new != NULL)
		new->below = stack;
	return (new);
}

t_stack	*pop(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	return (stack->below);
}

t_stack	*peek(t_stack *stack)
{
	return (stack->content);
}
