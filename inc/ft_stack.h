/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:59:39 by gade-oli          #+#    #+#             */
/*   Updated: 2023/08/01 12:41:19 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# ifndef SUCCESS
#  define SUCCESS 0
# endif

# ifndef FAIL
#  define FAIL -1
# endif

typedef struct s_stack
{
	void	*content;
	struct s_stack	*next;
}	t_stack;

int		ft_stsize(t_stack *stack);
t_stack	*ft_stnew(void *content);
t_stack	*ft_stpeek(t_stack **stack);
int	ft_stpop(t_stack **stack);
int	ft_stpush(t_stack **stack, t_stack *new_stacked);

#endif
