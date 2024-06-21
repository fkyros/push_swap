/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:39:15 by gade-oli          #+#    #+#             */
/*   Updated: 2024/06/21 14:28:37 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../megalibft/libft.h"

/*stack implementation for integers using a linked list*/
/*made for the push_swap project*/

typedef struct	s_stack
{
	int		content;
	struct s_stack	*below;
}	t_stack;

t_stack	*stack_new(int content);
int	size(t_stack *stack);
t_stack	*push(t_stack *stack, int content);
t_stack	*pop(t_stack *stack);
int	peek(t_stack *stack);

void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);
