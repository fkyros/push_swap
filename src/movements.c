/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:04:03 by gade-oli          #+#    #+#             */
/*   Updated: 2024/08/29 17:53:36 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//TODO: better error control returning int?

/**
 * swaps the order of the first two elements of the given stack
 * doesnt do anything if the stack has less than two items
 */
void	swap(t_list **stack, char name, int output)
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
	if (output)
	{
		write(STDIN_FILENO, "s", 1);
		write(STDIN_FILENO, &name, 1);
		write(STDIN_FILENO, "\n", 1);
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
	*from = aux->next;
	ft_lstadd_front(to, aux);
	write(STDIN_FILENO, "p", 1);
	write(STDIN_FILENO, &to_name, 1);
	write(STDIN_FILENO, "\n", 1);
}

/**
 * the first element becomes the last one
 * if the stack has more than one element
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
		write(STDIN_FILENO, "r", 1);
		write(STDIN_FILENO, &name, 1);
		write(STDIN_FILENO, "\n", 1);
	}
}

/**
 * the last element of the stack becomes the first one
 */
void	reverse_rotate(t_list **stack, char name, int output)
{
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	last = ft_lstlast(*stack);
	ft_lstadd_front(stack, ft_lstnew(last->content));
	ft_lstdelone(last);
	if (output)
	{
		write(STDIN_FILENO, "r", 1);
		write(STDIN_FILENO, &name, 1);
		write(STDIN_FILENO, "\n", 1);
	}
}
