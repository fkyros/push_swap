/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:04:03 by gade-oli          #+#    #+#             */
/*   Updated: 2024/08/05 22:19:53 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_list **stack, char name)
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
	write(STDIN_FILENO, "s", 1);
	write(STDIN_FILENO, &name, 1);
	write(STDIN_FILENO, "\n", 1);
}
