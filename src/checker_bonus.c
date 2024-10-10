/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:47:50 by gade-oli          #+#    #+#             */
/*   Updated: 2024/10/10 21:06:45 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	valid_move(char *movement)
{
	if (!ft_strcmp(movement, "ra\n"))
		return (1);
	if (!ft_strcmp(movement, "rb\n"))
		return (1);
	if (!ft_strcmp(movement, "rr\n"))
		return (1);
	if (!ft_strcmp(movement, "rra\n"))
		return (1);
	if (!ft_strcmp(movement, "rrb\n"))
		return (1);
	if (!ft_strcmp(movement, "rrr\n"))
		return (1);
	if (!ft_strcmp(movement, "pa\n"))
		return (1);
	if (!ft_strcmp(movement, "pb\n"))
		return (1);
	if (!ft_strcmp(movement, "sa\n"))
		return (1);
	if (!ft_strcmp(movement, "sb\n"))
		return (1);
	if (!ft_strcmp(movement, "ss\n"))
		return (1);
	return (0);
}

void	exec_move(char *movement, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(movement, "ra\n"))
		rotate(stack_a, 'a', 0);
	if (!ft_strcmp(movement, "rb\n"))
		rotate(stack_b, 'b', 0);
	if (!ft_strcmp(movement, "rr\n"))
		rr(stack_a, stack_b, 0);
	if (!ft_strcmp(movement, "rra\n"))
		reverse_rotate(stack_a, 'a', 0);
	if (!ft_strcmp(movement, "rrb\n"))
		reverse_rotate(stack_b, 'b', 0);
	if (!ft_strcmp(movement, "rrr\n"))
		rrr(stack_a, stack_b, 0);
	if (!ft_strcmp(movement, "pa\n"))
		push(stack_b, stack_a, 'a', 0);
	if (!ft_strcmp(movement, "pb\n"))
		push(stack_a, stack_b, 'b', 0);
	if (!ft_strcmp(movement, "sa\n"))
		swap(stack_a, 'a', 0);
	if (!ft_strcmp(movement, "sb\n"))
		swap(stack_b, 'b', 0);
	if (!ft_strcmp(movement, "ss\n"))
		ss(stack_a, stack_b, 0);
	free(movement);
}

int	print_result(t_list *stack_a, t_list *stack_b)
{
	if (!is_sorted(&stack_a) || ft_lstsize(stack_b))
	{
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
		ft_putstr_fd("KO\n", STDOUT_FILENO);
		return (1);
	}
	ft_putstr_fd("OK\n", STDOUT_FILENO);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}

int	free_and_return_error(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	return (print_error());
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	char		*movement;

	if (argc <= 1)
		return (1);
	stack_b = NULL;
	stack_a = parse_numbers(argc, argv);
	if (!stack_a)
		return (1);
	if (has_repeated(&stack_a))
		return (free_and_return_error(&stack_a, &stack_b));
	movement = get_next_line(STDIN_FILENO);
	while (movement)
	{
		if (!valid_move(movement))
		{
			free(movement);
			return (free_and_return_error(&stack_a, &stack_b));
		}
		exec_move(movement, &stack_a, &stack_b);
		movement = get_next_line(STDIN_FILENO);
	}
	free(movement);
	return (print_result(stack_a, stack_b));
}
