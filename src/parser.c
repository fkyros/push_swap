/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:38:29 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/26 19:55:06 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

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

char	**get_input_as_char_matrix(int argc, char **argv)
{
	int	i;
	char	*base;

	base = ft_strdup(argv[1]);
	if (!base)
		return (NULL);
	i = 2;
	while (i < argc)
	{
		base = ft_strjoin((const char *)base, (const char *)" ");
		base = ft_strjoin((const char *)base, (const char *)argv[i]);
		if (!base)
			return (NULL);
		i++;
	}
	return (ft_split(base, ' '));
}

/*
 * return the numbers of ints parsed from the input on the matrix
 */
int	get_number_of_numbers(char **matrix)
{
	int	res;

	res = 0;
	while (matrix[res])
		res++;
	return (res);
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
	char		**num_matrix;

	num_matrix = get_input_as_char_matrix(argc, argv);
	if (!num_matrix)
		return (NULL);
	i = get_number_of_numbers(num_matrix) - 1;
	content = ft_atoi(num_matrix[i]);
	if (input_not_valid(content, argv[i + 1]))
		return (NULL);
	i--;
	stack = ft_lstnew(content);
	while (i >= 0)
	{
		content = ft_atoi(num_matrix[i]);
		if (input_not_valid(content, argv[i + 1]))
		{
			ft_lstclear(&stack);
			return (NULL);
		}
		ft_lstadd_front(&stack, ft_lstnew((int)content));
		i--;
	}
	return (stack);
}
