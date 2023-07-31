/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:59:06 by gade-oli          #+#    #+#             */
/*   Updated: 2023/07/31 20:06:45 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	valid_input(char **argv)
{
}

t_list	parse(int argc, char **argv)
{
	t_list	**res;
	t_list	*aux;
	int		num;
	int		i;

	if (!check_input(argv))
		return (NULL);
	i = 0;
	while (i < argc)
	{
		num = atoi(argv[i]);
		aux = ft_lstnew(num);
		res = ft_lstadd_back(res, );
	}
}
