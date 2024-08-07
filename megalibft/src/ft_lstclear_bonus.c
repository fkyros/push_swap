/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:07:15 by gade-oli          #+#    #+#             */
/*   Updated: 2024/08/05 21:36:16 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*aux;

	if (*lst)
	{
		while (*lst)
		{
			aux = (*lst)->next;
			ft_lstdelone(*lst);
			*lst = aux;
		}
		*lst = NULL;
	}
}
