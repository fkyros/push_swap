/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:06:21 by gade-oli          #+#    #+#             */
/*   Updated: 2024/06/21 18:25:58 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;

	if (argc <= 1)
		return (0);
	a = create_stack(argc, argv);
	if (!a)
		return (1);
	print_stack(a);
	//if (is_sorted(a))
	//	return (0);
	//sort_stack(a, b);
	free_stack(a);
	return (0);
}
