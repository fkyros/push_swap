/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:39:15 by gade-oli          #+#    #+#             */
/*   Updated: 2024/06/06 18:04:41 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../megalibft/libft.h"

typedef struct	s_stack
{
	void		*content;
	struct s_stack	*below;
}	t_stack;

t_stack	*stack_new(void	*content);
int	size(t_stack *stack);
t_stack	*push(void *content, t_stack *stack);
t_stack	*pop(t_stack *stack);
void	*seek(t_stack *stack);
