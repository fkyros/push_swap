/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:39:52 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/17 17:21:36 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	count_rotations(t_list **stack, unsigned int index)
{
	int	res;
	int	flag;

	res = 0;
	flag = 0;
	while (!flag && stack)
	{
		if ((*stack)->index == index)
			flag = 1;
		else
			res++;
		*stack = (*stack)->next;
	}
	return (res);
}
