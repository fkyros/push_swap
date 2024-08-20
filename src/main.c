/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:34:21 by gade-oli          #+#    #+#             */
/*   Updated: 2024/08/20 18:02:36 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = ft_lstnew(2);
	if (argc <= 1)
		return (1);
	stack_a = parse_numbers(argc, argv);
	if (!stack_a)
		return (1);
	if (is_sorted(&stack_a) || has_repeated(&stack_a))
		return (1);
	//k-sort
	
	print_stack(&stack_a);

	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
