/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:38:29 by gade-oli          #+#    #+#             */
/*   Updated: 2024/08/29 16:54:46 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * prints "Error\n" on stderr if the input does not have an integer
 * DISCLAIMER:
 * 	it checks for 0 because ft_atoi returns 0 if the 
 * 	original parameter was not a valid number
 */
int	input_not_valid(long content, char *original)
{
	if ((content == 0 && ft_strcmp(original, "0") != 0) ||
		(content > INT_MAX || content < INT_MIN))
		return (print_error());
	return (0);
}

/**
 * given a stdin input of integers, returns the created stack
 * if malformed, returns NULL and prints Error
 */
t_list	*parse_numbers(int argc, char **argv)
{
	long		content;
	int		i;
	t_list	*stack;

	i = argc - 1;
	content = ft_atoi(argv[i]);
	if (input_not_valid(content, argv[i]))
		return (NULL);
	i--;
	stack = ft_lstnew(content);
	while (i >= 1)
	{
		content = ft_atoi(argv[i]);
		if (input_not_valid(content, argv[i]))
		{
			ft_lstclear(&stack);
			return (NULL);
		}
		ft_lstadd_front(&stack, ft_lstnew((int)content));
		i--;
	}
	return (stack);
}
