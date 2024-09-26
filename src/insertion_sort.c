/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:34:21 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/04 21:29:32 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*list_to_array(t_list *list)
{
	int	size;
	int	*array;
	int	i;

	size = ft_lstsize(list);
	if (size < 1)
		return (NULL);
	array = (int *) malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = list->content;
		list = list->next;
		i++;
	}
	return (array);
}

void	insertion_sort(int *array, int size)
{
	int	key;
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
		i++;
	}
}

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
				stack->index = j;
				flag = 1;
			}
			j++;
		}
		flag = 0;
		stack = stack->next;
		i++;
	}
}