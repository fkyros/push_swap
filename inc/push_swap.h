/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:34:44 by gade-oli          #+#    #+#             */
/*   Updated: 2024/08/05 21:54:32 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../megalibft/libft.h"

//parser.c
t_list	*parse_numbers(int argc, char **argv);

//utils.c
void	print_stack(t_list **a);

//is_sorted.c
int		is_sorted(t_list **stack);
