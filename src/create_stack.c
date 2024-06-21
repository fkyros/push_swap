/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:38:29 by gade-oli          #+#    #+#             */
/*   Updated: 2024/06/21 18:30:31 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	input_not_valid(int content, char *original)
{
	if (content == 0 && ft_strcmp(original, "0") != 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

t_stack	*create_stack(int argc, char **argv)
{
	int	content;
	int	i;
	t_stack	*stack;

	i = argc - 1;
	content = ft_atoi(argv[i]);
	if (input_not_valid(content, argv[i]))
		return (NULL);
	i--;
	stack = stack_new(content);
	while (i >= 1)
	{
		content = ft_atoi(argv[i]);
		if (input_not_valid(content, argv[i]))
		{
			free_stack(stack);
			return (NULL);
		}
		stack = push(stack, content);
		i--;
	}
	return (stack);
}
