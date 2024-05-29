/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:39:25 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/29 20:50:36 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void	ft_lstadd_back(t_polynomial **lst, t_polynomial *new)
{
	t_polynomial	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

t_polynomial	*ft_lstnew(int coefficient, int exponent)
{
	t_polynomial	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->coefficient = coefficient;
	list->exponent = exponent;
	list->next = NULL;
	return (list);
}

int	ft_lstsize(t_polynomial *lst)
{
	int		len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
