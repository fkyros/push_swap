/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:52:39 by gade-oli          #+#    #+#             */
/*   Updated: 2024/06/06 22:17:17 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*swap(t_stack *x)
{
	t_stack *tmp;

	if (size(x) < 2)
		return (NULL);
	tmp = x;
	x = x->below;
	x->below = tmp;
	return (x);
}
