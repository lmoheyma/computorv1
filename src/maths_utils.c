/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:00:18 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/31 21:40:12 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

float ft_fabs(float nb) {
	return (nb < 0.0 ? -nb : nb);
}

float ft_pgcd(float a, float b) {
	if (a < b)
		return ft_pgcd(b, a);
	if (ft_fabs(b) < 0.001)
		return (a);
	else
		return (ft_pgcd(b, a - floor(a / b) * b));
}

float ft_sqrt(float nb) {
	int i;

	for (i = 0; i * i <= nb; i++)
		;
	float lower_bound = i - 1;
	if (lower_bound * lower_bound == nb)
		return (lower_bound);
	float upper_bound = i;
	float prev_ub = upper_bound;
	for (int j = 0; j <= 20; j++) {
		float upper_bound2 = upper_bound * upper_bound;
		if (upper_bound2 > nb) {
			prev_ub = upper_bound;
			upper_bound = (lower_bound + upper_bound) / 2;
		}
		else {
			lower_bound = upper_bound;
			upper_bound = prev_ub;
		}
	}
	return (upper_bound);
}

int	polynomial_degree(t_polynomial *terms)
{
	int	polynomial_degree = 0;

	while (terms)
	{
		if (terms->exponent > polynomial_degree)
			polynomial_degree = terms->exponent;
		terms = terms->next;
	}
	printf(BOLDWHITE"Polynomial degree: "RESET"%d\n", polynomial_degree);
	if (polynomial_degree > 2) {
		printf(BOLDRED"The polynomial degree is strictly greater than 2, I can't solve.\n"RESET);
		return (-1);
	}
	return (polynomial_degree);
}
