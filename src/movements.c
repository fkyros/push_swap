/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:52:39 by gade-oli          #+#    #+#             */
/*   Updated: 2024/06/21 18:27:56 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
t_stack	*swap(t_stack *x)
{
	t_stack *tmp;

	if (size(x) < 2)
		return (NULL);
	tmp = x;
	x = x->below;
	x->below = tmp;
	return (x);
}
*/

t_stack	*swap(t_stack *x)
{
	int	first;
	int	second;

	if (size(x) < 2)
		return (NULL);
	first = peek(x);
	x = pop(x);
	second = peek(x);
	x = pop(x);
	x = push(x, first);
	x = push(x, second);
	return (x);
}

t_stack	*get_second_last_element(t_stack *x)
{	
	if (x == NULL)	
		return (NULL);
	while (x->below != NULL && x->below->below != NULL)
		x = x->below;
	return (x);

}

t_stack	*get_last_element(t_stack *x)
{
	if (x == NULL)
		return (NULL);
	while (x->below != NULL)
		x = x->below;
	return (x);
}

t_stack	*rotate(t_stack *x)
{
	t_stack	*first;
	t_stack	*last;

	first = stack_new(peek(x));
	last = get_last_element(x);
	last->below = first;
	return (pop(x));
}

t_stack	*reverse_rotate(t_stack *x)
{
	t_stack *last;
	t_stack *second_last;

	last = get_last_element(x);
	second_last = get_second_last_element(x);
	x = push(x, last->content);
	free(last);
	second_last->below = NULL;
	return (x);
}
