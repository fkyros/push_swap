/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:06:39 by gade-oli          #+#    #+#             */
/*   Updated: 2024/10/08 17:03:25 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 * looks for the last node in the stack, deletes it and gives the clone
 */
t_list	*ft_lstclone_and_delete_last(t_list **stack, t_list *node)
{
	t_list	*res;
	t_list	*list;

	if (!node)
		return (NULL);
	res = ft_lstnew(node->content);
	res->index = node->index;
	list = *stack;
	while (list && list->next && list->next->content != node->content)
		list = list->next;
	if (list)
		list->next = NULL;
	ft_lstdelone(node);
	return (res);
}

void	*free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix || !matrix[0])
		return (NULL);
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

int	has_repeated(t_list **stack)
{
	t_list	*iter;
	t_list	*iter_aux;
	int		value;

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

int	print_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (1);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb == 0 || nb == 1)
		return (nb);
	else if (nb >= 2)
	{
		while (i * i < nb)
			i++;
		return (i);
	}
	return (0);
}
