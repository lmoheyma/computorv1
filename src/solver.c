/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:14:01 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/30 22:45:00 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

static void change_sign(t_polynomial *terms) {
	t_polynomial *temp = terms;

	while (temp) {
		(temp->sign == '-' ? temp->coefficient *= -1 : 0);
		temp = temp->next;
	}
}

static t_coef reduce_side(t_polynomial *terms) {
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
	
	change_sign(left_terms);
	change_sign(right_terms);
	left_coef = reduce_side(left_terms);
	printf("a = %.1f, b = %.1f, c = %.1f\n", left_coef.a, left_coef.b, left_coef.c);
	right_coef = reduce_side(right_terms);
	printf("a = %.1f, b = %.1f, c = %.1f\n", right_coef.a, right_coef.b, right_coef.c);
}