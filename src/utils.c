/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:02:16 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/31 00:16:48 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

int	polynomial_degree(t_polynomial *terms)
{
	int	polynomial_degree = 0;

	while (terms)
	{
		if (terms->exponent > polynomial_degree)
			polynomial_degree = terms->exponent;
		terms = terms->next;
	}
	printf("Polynomial degree: %d\n", polynomial_degree);
	if (polynomial_degree > 2) {
		printf("The polynomial degree is strictly greater than 2, I can't solve.\n");
		return (-1);
	}
	return (polynomial_degree);
}

void	free_all(t_polynomial *terms, t_polynomial *left_terms,
		t_polynomial *right_terms)
{
	free_list(terms);
	free_list(left_terms);
	free_list(right_terms);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

void	print_error(char *error_msg)
{
	write(2, error_msg, strlen(error_msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}