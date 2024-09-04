/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:03:21 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/04 21:37:26 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	indexer(t_list *stack, int *array, int size)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (!flag && j < size)
		{
			if (stack->content == array[j])
			{
				stack->index = i;
				flag = 1;
			}
			j++;
		}
		flag = 0;
		stack = stack->next;
		i++;
	}
}
