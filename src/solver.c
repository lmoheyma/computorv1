/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:14:01 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/30 21:00:14 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

t_coef reduce_side(t_polynomial *terms) {
	t_coef coefs;
	
	while (terms) {
		if (terms->exponent == 0)
			coefs.c += terms->coefficient;
		else if (terms->exponent == 1)
			coefs.b += terms->coefficient;
		else
			coefs.a += terms->coefficient;
		terms = terms->next;
	}
	return (coefs);
}

void reduce_equation(t_polynomial *left_terms, t_polynomial *right_terms) {
	t_coef left_coef;
	t_coef right_coef;
	
	left_coef = reduce_side(left_terms);
	printf("a = %.1f, b = %.1f, c = %.1f\n", left_coef.a, left_coef.b, left_coef.c);
	right_coef = reduce_side(right_terms);
	printf("a = %.1f, b = %.1f, c = %.1f\n", right_coef.a, right_coef.b, right_coef.c);
}