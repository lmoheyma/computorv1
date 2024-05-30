/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:39:25 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/30 15:21:00 by lmoheyma         ###   ########.fr       */
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
	list->sign = '+';
	list->coefficient = coefficient;
	list->exponent = exponent;
	list->separator = 0;
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

t_polynomial	*ft_lstlast(t_polynomial *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}


void print_lst(t_polynomial *terms) {
	int i = 0;
	
	while (terms) {
		printf("Terms[%d] : %d * X^%d\n", i, terms->coefficient, terms->exponent);
		terms = terms->next;
		i++;
	}
}