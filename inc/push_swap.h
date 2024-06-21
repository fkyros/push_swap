/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:53:38 by gade-oli          #+#    #+#             */
/*   Updated: 2024/06/21 18:25:28 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "../megalibft/libft.h"

//valid for stack_a and stack_b
t_stack *swap(t_stack *x);
t_stack *rotate(t_stack *x);
t_stack *reverse_rotate(t_stack *x);

t_stack	*create_stack(int argc, char **agrv);
int	input_not_valid(int content, char *original);
