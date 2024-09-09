/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:28:46 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/09 23:20:18 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 * ir por chunks. 
 *
 */
void	ksort_range(t_list *stack_a, t_list *stack_b, int original_size)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(original_size) * 14/10; //why 1,4?? why sqrt??
	while (stack_a->next)
	{
		//if (valor_pila en rango 0, i)
		//	pb
		//	
		//if (valor_pila en rango i, rango)
		//	pb
		//	rrb
		//else
		//	ra
		//o algo asi
		i++;
	}
}

//void	ksort_back_to_a
