/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:04:03 by gade-oli          #+#    #+#             */
/*   Updated: 2024/08/13 20:49:23 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//TODO: better error control returning int?

/**
 * swaps the order of the first two elements of the given stack
 * doesnt do anything if the stack has less than two items
 */
void	swap(t_list **stack, char name, int write)
{
	t_list	*first;
	t_list	*second;
	int	aux;

	if (ft_lstsize(*stack) < 2)
		return ;
	first = *stack;
	second = first->next;
	aux = second->content;
	second->content = first->content;
	first->content = aux;
	if (write)
	{
		write(STDIN_FILENO, "s", 1);
		write(STDIN_FILENO, &name, 1);
		write(STDIN_FILENO, "\n", 1);
	}
}

/**
 * adds to the stack a new node with the value and prints the movement
 */
void	push(t_list **stack, int value, char name)
{
	t_list	*new;

	new = ft_lstnew(value);
	if (!new)
		return ;
	ft_lstadd_front(stack, new);
	write(STDIN_FILENO, "p", 1);
	write(STDIN_FILENO, &name, 1);
	write(STDIN_FILENO, "\n", 1);
}

/**
 * the first element becomes the last one
 * if the stack has more than one element
 */
void	rotate(t_list **stack, char name. int write)
{
	t_list	*aux;

	if (ft_lstsize(*stack) < 2)
		return ;
	aux = *stack;
	*stack = *stack->next
	ft_lstadd_back(stack, aux);
	if (write)
	{
		write(STDIN_FILENO, "r", 1);
		write(STDIN_FILENO, &name, 1);
		write(STDIN_FILENO, "\n", 1);
	}
}
