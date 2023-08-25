/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:59:06 by gade-oli          #+#    #+#             */
/*   Updated: 2023/08/25 15:27:44 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * returns 1 if a string only contains integers 
 * (and or a + or - symbol at the beginning)
 */
int	is_number(char *str)
{
	int	i;
	int	tam;

	i = 0;
	tam = ft_strlen(str);
	if (str[i] == '+' || str[i] == '-' || ft_isdigit(str[i]))
		i++;
	while (i <= tam)
	{
		if (!ft_isdigit(str[i] - '0'))
			return (0);
		i++;
	}
	return (1);
}

/**
 * checks if a given int array (and its size) already contains a number 
 */
int	is_duplicated(int num, int *array, int tam)
{
	int	i;

	i = 0;
	while (i < tam)
	{
		if (array[i] == num)
			return (1);
		i++;
	}
	return (0);
}

/**
 * returns 0 if the input does not contain duplicates, are
 * not integers, or superior or inferior to max and min integers
 */
int	valid_input(int argc, char **argv)
{
	int	i;
	int	num;
	int	*array;

	i = 1;
	array = malloc(sizeof(int) * argc - 1);
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			free(array);
			return (1);
		}
		num = ft_atoi(argv[i]);
		if (num >= INT_MAX || num <= INT_MIN)
		{
			free(array);
			return (1);
		}
		if (is_duplicated(num, array, i))
		{
			free(array);
			return (1);
		}
		*(array + i) = num;
		i++;
	}
	return (0);
}

/**
 * returns a t_stack of a clean input given
 */
/*t_stack	**parse(int argc, char **argv)
{
	t_stack	**res;
	t_stack	*aux;
	int		num;
	int		i;

	if (!check_input(argv))
		return (NULL);
	i = 0;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		aux = ft_lstnew(num);
		res = ft_lstadd_back(res, );
		i++;
	}
	return (res);
}*/
