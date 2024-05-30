/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:39:25 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/30 18:06:20 by lmoheyma         ###   ########.fr       */
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

t_polynomial	*ft_lstnew(double coefficient, int exponent, char sign, int flag)
{
	t_polynomial	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->sign = sign;
	list->coefficient = coefficient;
	list->exponent = exponent;
	list->separator = flag;
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
	
	if (!terms)
		return ;
	terms = terms->next;
	while (terms) {
		if (terms->separator)
			printf("\n<-- Separator [=] -->\n\n");
		else
			printf("Terms[%d] : %c%.1f * X^%d\n", i, terms->sign, terms->coefficient, terms->exponent);
		terms = terms->next;
		i++;
	}
}