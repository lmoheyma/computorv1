/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:14:01 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/30 23:54:27 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

static void display_reduced(t_coef left_coefs, t_polynomial *terms) {
	(void)terms;

	printf("Reduced form: ");
	(left_coefs.a != 0.0) ? printf("%.1f * X^2", left_coefs.a) : 0;
	(left_coefs.a != 0.0 && left_coefs.b != 0.0) ? printf(" + ") : 0;
	(left_coefs.b != 0.0) ? printf("%.1f * X", left_coefs.b) : 0;
	((left_coefs.b != 0.0 && left_coefs.c != 0.0) 
		|| (left_coefs.a != 0.0 && left_coefs.c != 0.0)) ? printf(" + ") : 0;
	(left_coefs.c != 0.0) ? printf("%.1f", left_coefs.c) : 0;
	printf(" = 0\n");
}

static void change_sign(t_polynomial *terms) {
	t_polynomial *temp = terms;

	while (temp) {
		(temp->sign == '-' ? temp->coefficient *= -1 : 0);
		temp = temp->next;
	}
}

static t_coef *reduce_side(t_polynomial *terms, t_coef *coefs) {
	// t_coef coefs;
	
	while (terms) {
		if (terms->exponent == 0)
			coefs->c += terms->coefficient;
		else if (terms->exponent == 1)
			coefs->b += terms->coefficient;
		else
			coefs->a += terms->coefficient;
		terms = terms->next;
	}
	return (coefs);
}

void reduce_equation(t_polynomial *left_terms, t_polynomial *right_terms) {
	t_coef left_coef = {0.0, 0.0, 0.0};
	t_coef right_coef = {0.0, 0.0, 0.0};
	
	change_sign(left_terms);
	change_sign(right_terms);
	reduce_side(left_terms, &left_coef);
	reduce_side(right_terms, &right_coef);
	(right_coef.a != 0.0) ? left_coef.a -= right_coef.a : 0;
	(right_coef.b != 0.0) ? left_coef.b -= right_coef.b : 0;
	(right_coef.c != 0.0) ? left_coef.c -= right_coef.c : 0;
	right_coef = (t_coef){0.0, 0.0, 0.0};
	printf("a = %.1f, b = %.1f, c = %.1f\n", left_coef.a, left_coef.b, left_coef.c);
	display_reduced(left_coef, left_terms);
}