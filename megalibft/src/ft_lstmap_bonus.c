/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:12:58 by gade-oli          #+#    #+#             */
/*   Updated: 2024/08/05 21:37:07 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*res;
	t_list	*element;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	while (lst)
	{
		element = ft_lstnew(f(lst->content));
		if (!element)
		{
			ft_lstclear(&res);
			return (NULL);
		}
		ft_lstadd_back(&res, element);
		lst = lst->next;
	}
	return (res);
}
