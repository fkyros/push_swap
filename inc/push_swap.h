/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:33:31 by gade-oli          #+#    #+#             */
/*   Updated: 2023/08/25 15:20:03 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_stack.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
//# include "stack.h"
# include "limits.h"

//parsing
int		valid_input(int argc, char **argv);
t_stack	*parse(int argc, char **argv);

//TODO: input indexing -> data field from t_stack has two integers: value and index

//error
void	ft_error();

//push_swap instructions
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a);
void	pb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
