/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:34:21 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/23 16:06:27 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_list			*stack_a;
	t_list			*stack_b;
	int				*array;
	unsigned int	size;

	if (argc <= 1)
		return (1);
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
	indexer(stack_a, array, size);
	free(array);
	sort_stack(&stack_a, &stack_b, size);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
