/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:04:03 by gade-oli          #+#    #+#             */
/*   Updated: 2024/08/07 17:22:08 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//TODO: better error control returning int?

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
