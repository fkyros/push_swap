/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:34:44 by gade-oli          #+#    #+#             */
/*   Updated: 2024/09/04 21:18:25 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../megalibft/libft.h"
# include <limits.h>

//parser.c
t_list	*parse_numbers(int argc, char **argv);

//utils.c
void	print_stack(t_list **stack);
int	has_repeated(t_list **stack);
int	print_error();

//is_sorted.c
int		is_sorted(t_list **stack);

//movements,c
void	swap(t_list **stack, char name, int write);
void	push(t_list **from, t_list **to, char to_name);
void	rotate(t_list **stack, char name, int output);
void	reverse_rotate(t_list **stack, char name, int output);

//double_movements.c
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

//indexer.c
void	indexer(t_list *stack, int *array, int size);

//insertion_sort.c
int	*list_to_array(t_list *list);
void	insertion_sort(int *array, int size);

#endif
