/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:19:20 by gade-oli          #+#    #+#             */
/*   Updated: 2023/10/16 22:32:38 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	if (!s)
		return (NULL);
	while (!found && s[i])
	{
		if (s[i] == (char)c)
			found = 1;
		else
			i++;
	}
	if ((char)c == '\0' && s[i] == '\0')
		found = 1;
	if (found)
		return ((char *)(s + i));
	return (NULL);
}
