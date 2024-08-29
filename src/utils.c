/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:06:39 by gade-oli          #+#    #+#             */
/*   Updated: 2024/08/29 15:59:34 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_list **stack)
{
	t_list	*iter;
	int		i;

	i = 0;
	iter = *stack;
	while (iter)
	{
		ft_printf("stack[%d] = %d\n", i, iter->content);
		iter = iter->next;
		i++;
	}
	ft_printf("stack[%d] = NULL\n", i);
}

int	has_repeated(t_list **stack)
{
	t_list	*iter;
	t_list	*iter_aux;
	int	value;

	iter = *stack;
	while (iter->next)
	{
		value = iter->content;
		iter_aux = iter->next;
		while (iter_aux->next)
		{
			if (value == iter_aux->content)
				return (1);
			iter_aux = iter_aux->next;
		}
		iter = iter->next;
	}
	return (0);
}

int	print_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (1);
}
