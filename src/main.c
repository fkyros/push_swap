/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:34:21 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/20 19:08:20 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

#include <stdio.h> //quitar!!
int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	int		*array;
	unsigned int	size;

	stack_a = parse_numbers(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		return (1);
	if (has_repeated(&stack_a))
		return (ft_lstclear(&stack_a), print_error());
	if (is_sorted(&stack_a))
		return (ft_lstclear(&stack_a), 1);

	size = ft_lstsize(stack_a);
	array = list_to_array(stack_a);
	insertion_sort(array, size);
	//for (unsigned int i = 0; i < size; i++)
	//	printf("%d ", array[i]);
	indexer(stack_a, array, size);
	free(array);
	//print_stack(&stack_a);

	/*
	if (size < 12)
		small_sort(&stack_a, &stack_b, size);
	else
	{*/
		ksort_range_in_b(&stack_a, &stack_b, size);
		ksort_back_to_a(&stack_a, &stack_b, size);
	//}
	//print_stack(&stack_a);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
