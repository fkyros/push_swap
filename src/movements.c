/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:04:03 by gade-oli          #+#    #+#             */
/*   Updated: 2024/10/08 16:34:15 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * swaps the order of the first two elements of the given stack
 * doesnt do anything if the stack has less than two items
 */
void	swap(t_list **stack, char name, int output)
{
	t_list	*first;
	t_list	*second;
	int		value_aux;
	int		index_aux;

	if (ft_lstsize(*stack) < 2)
		return ;
	first = *stack;
	second = first->next;
	value_aux = second->content;
	index_aux = second->index;
	second->content = first->content;
	second->index = first->index;
	first->content = value_aux;
	first->index = index_aux;
	if (output)
	{
		write(STDOUT_FILENO, "s", 1);
		write(STDOUT_FILENO, &name, 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * moves the first element from the stack "from" to "to"
 */
void	push(t_list **from, t_list **to, char to_name)
{
	t_list	*aux;

	if (ft_lstsize(*from) < 1)
		return ;
	aux = *from;
	*from = (*from)->next;
	ft_lstadd_front(to, aux);
	write(STDOUT_FILENO, "p", 1);
	write(STDOUT_FILENO, &to_name, 1);
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * the first element becomes the last one
 */
void	rotate(t_list **stack, char name, int output)
{
	t_list	*aux;

	if (ft_lstsize(*stack) < 2)
		return ;
	aux = *stack;
	*stack = aux->next;
	ft_lstadd_back(stack, aux);
	if (output)
	{
		write(STDOUT_FILENO, "r", 1);
		write(STDOUT_FILENO, &name, 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * the last element of the stack becomes the first one
 */
void	reverse_rotate(t_list **stack, char name, int output)
{
	t_list	*last;
	t_list	*new_front;
	t_list	*stack_iter;

	if (ft_lstsize(*stack) < 2)
		return ;
	stack_iter = *stack;
	last = ft_lstlast(stack_iter);
	new_front = ft_lstclone_and_delete_last(stack, last);
	ft_lstadd_front(stack, new_front);
	if (output)
	{
		write(STDOUT_FILENO, "rr", 2);
		write(STDOUT_FILENO, &name, 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}
