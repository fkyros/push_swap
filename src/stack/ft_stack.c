/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:20:16 by gade-oli          #+#    #+#             */
/*   Updated: 2023/08/01 13:58:57 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_stack.h"

/**
 * returns the size of a given stack, or FAIL if the stack does not exist
 */
int	ft_stsize(t_stack *stack)
{
	int	i;

	if (!stack)
		return (FAIL);
	i = 0;
	while (stack)
	{
		i++;
		if (!stack->next)
			return (i);
		stack = stack->next;
	}
	return (i);
}

/**
 * returns a new t_stack with the content given, and the "next" member pointing to NULL 
 */
t_stack	*ft_stnew(void *content)
{
	t_stack	*res;

	if (!content)
		return (NULL);
	res = malloc(sizeof(t_stack *));
	res->content = content;
	res->next = NULL;
	return (res);
}

/**
 * returns the t_stack that is on top of the stack
 */
t_stack	*ft_stpeek(t_stack **stack)
{
	if (!stack)
		return (NULL);
	return (*stack);
}

/**
 * returns SUCCESS if the first element was correctly free and removed 
 * from the stack, or FAIL if the stack doesn't exist
 */
int	ft_stpop(t_stack **stack)
{
	t_stack	**aux;

	if (!stack)
		return (FAIL);
	aux = stack;
	aux++;
	free(*stack);
	stack = aux;
	return (SUCCESS);
}

/**
 * returns SUCCESS if the new_stacked was properly added to the first position of the stack,
 * or FAIL if the stack or the new_stacked don't exist
 */
int	ft_stpush(t_stack **stack, t_stack *new_stacked)
{
	if (!stack || !new_stacked)
		return (FAIL);
	new_stacked->next = *stack;
	return (SUCCESS);
}
