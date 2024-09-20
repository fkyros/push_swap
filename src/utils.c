/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:06:39 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/20 18:45:14 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*ft_lstclone(t_list *node)
{
	t_list	*res;

	if (!node)
		return (NULL);
	res = ft_lstnew(node->content);
	res->index = node->index;
	ft_lstdelone(node);
	return (res);
}

void	print_stack(t_list **stack)
{
	t_list	*iter;
	int		i;

	i = 0;
	iter = *stack;
	while (iter)
	{
		ft_printf("stack[%d] = %d\n", i, iter->content);
		ft_printf("\t->index = %d\n", iter->index);
		iter = iter->next;
		i++;
	}
	ft_printf("stack[%d] = NULL\n\n", i);
}

int	has_repeated(t_list **stack)
{
	t_list	*iter;
	t_list	*iter_aux;
	int	value;

	if (!stack || !*stack)
		return (0);
	iter = *stack;
	while (iter)
	{
		value = iter->content;
		iter_aux = iter->next;
		while (iter_aux)
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
