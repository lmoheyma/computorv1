/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:39:25 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/30 20:48:42 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void free_list(t_polynomial *terms) {
	t_polynomial	*temp;

	while (terms)
	{
		temp = terms->next;
		free(terms);
		terms = temp;
	}
}

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

t_polynomial	*ft_lstnew(float coefficient, int exponent, char sign, int flag)
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

void split_list(t_polynomial **terms, t_polynomial **left_terms, t_polynomial **right_terms) {
	t_polynomial *temp = *terms;

	if (!temp)
		return ;
	while (temp && temp->separator != 1) {
		ft_lstadd_back(left_terms, ft_lstnew(temp->coefficient, temp->exponent, temp->sign, temp->separator));
		temp = temp->next;
	}
	temp = temp->next;
	while (temp) {
		ft_lstadd_back(right_terms, ft_lstnew(temp->coefficient, temp->exponent, temp->sign, temp->separator));
		temp = temp->next;
	}
}

void print_lst(t_polynomial *terms) {
	int i = 0;
	
	if (!terms)
		return ;
	while (terms) {
		printf("Terms[%d] : %c%.1f * X^%d\n", i, terms->sign, terms->coefficient, terms->exponent);
		terms = terms->next;
		i++;
	}
}