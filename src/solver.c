/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:14:01 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/31 21:29:08 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"
#include <math.h>

static void irreductible_fraction(float *num, float *denominator) {
	float pgcd = ft_pgcd(ft_fabs(*num), ft_fabs(*denominator));
	
	(pgcd != 1.0) ? *num /= pgcd, *denominator /= pgcd : 0;
}

static void irreductible_fraction_quadratic(float *num_1, float *num_2, float *denominator_x1, float *denominator_x2) {
	float x1_pgcd = ft_pgcd(ft_fabs(*num_1), ft_fabs(*denominator_x1));
	float x2_pgcd = ft_pgcd(ft_fabs(*num_2), ft_fabs(*denominator_x2));
	
	(x1_pgcd != 1.0) ? *num_1 /= x1_pgcd, *denominator_x1 /= x1_pgcd : 0;
	(x2_pgcd != 1.0) ? *num_2 /= x2_pgcd, *denominator_x2 /= x2_pgcd  : 0;
}

static void display_reduced(t_coef left_coefs, t_polynomial *terms) {
	(void)terms;

	printf(BOLDWHITE"Reduced form: "RESET);
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

static t_coef reduce_equation(t_polynomial *left_terms, t_polynomial *right_terms) {
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
	display_reduced(left_coef, left_terms);
	return (left_coef);
}

int solve_equation(t_polynomial *left_terms, t_polynomial *right_terms, t_polynomial *terms) {
	int degree;
	t_coef coefs;
	
	coefs = reduce_equation(left_terms, right_terms);
	if ((degree = polynomial_degree(terms)) < 0)
		return (1);
	printf(BOLDCYAN"/* ************************************************* */\n");
	printf("/*"BOLDYELLOW"                       STEPS                       "BOLDCYAN"*/\n");
	printf(BOLDCYAN"/* ************************************************* */\n\n"RESET);
	if (coefs.a == 0.0) {
		if (coefs.b == 0) {
			if (coefs.c == 0.0) {
				printf(BOLDRED"Equation has infinite solutions\n"RESET);
			} else {
				printf(BOLDRED"Equation has no solution\n"RESET);
			}
		} else {
			printf(BOLDWHITE"Second-degree polynomial equation of the form:\n\tax + b = 0\n\n");
			printf(BOLDCYAN"Coefficients are a = %.2f and b = %.2f\n\n"RESET, coefs.b, coefs.c);
			float x0 = (-(coefs.c / coefs.b));
			irreductible_fraction(&coefs.c, &coefs.b);
			printf(BOLDWHITE"The solution is:\n\t"BOLDMAGENTA"x0"RESET" = "BOLDYELLOW"-(b / a)"RESET" = -(%.2f / %.2f) = "BOLDGREEN"%.2f\n"RESET, coefs.c, coefs.b, x0);
		}
	} else {
		float delta = (coefs.b * coefs.b) - (4 * coefs.a * coefs.c);
		printf(BOLDWHITE"Second-degree polynomial equation of the form:\n\tax^2 + bx + c = 0\n\n");
		printf(BOLDCYAN"Coefficients are a = %.2f, b = %.2f and c = %.2f\n\n"RESET, coefs.a, coefs.b, coefs.c);
		printf(BOLDMAGENTA"Discriminant"RESET" = "BOLDYELLOW"b^2 -4ac"RESET" = (%.2f * %.2f) - (4 * %.2f * %.2f) ≃ "BOLDGREEN"%.2f\n\n"RESET, coefs.b, coefs.b, coefs.a, coefs.c, delta);
		if (delta > 0) {
			float sqrt_delta = ft_sqrt(delta);
			float numerator_x1 = -coefs.b - sqrt_delta;
			float numerator_x2 = -coefs.b + sqrt_delta;
			float denominator_x1 = 2 * coefs.a;
			float denominator_x2 = 2 * coefs.a;
			irreductible_fraction_quadratic(&numerator_x1, &numerator_x2, &denominator_x1, &denominator_x2);
			printf(BOLDWHITE"Δ > 0 -> Discriminant is strictly "BOLDGREEN"positive"BOLDWHITE", the two solutions are:\n"RESET);
			float x1 = numerator_x1 / denominator_x1;
			float x2 = numerator_x2 / denominator_x2;
			printf(BOLDMAGENTA"\tx1"RESET" = "BOLDYELLOW"(-b - (sqrt(Δ) / 2a)"RESET" = (%.2f - %.2f) / (2 * %.2f) = %.2f / %.2f ≃ "BOLDGREEN"%.2f\n"RESET, coefs.b, sqrt_delta, coefs.a, numerator_x1, denominator_x1, x1);
			printf(BOLDMAGENTA"\tx2"RESET" = "BOLDYELLOW"(-b + (sqrt(Δ) / 2a)"RESET" = (%.2f + %.2f) / (2 * %.2f) = %.2f / %.2f ≃ "BOLDGREEN"%.2f\n", coefs.b, sqrt_delta, coefs.a, numerator_x2, denominator_x2, x2);
		} else if (delta == 0) {
			float x0 = -coefs.b / (2 * coefs.a);
			printf(BOLDWHITE"Δ < 0 -> The solution is:\n"RESET);
			printf(BOLDMAGENTA"\tx0"RESET" = "BOLDYELLOW"-b / (2a)"RESET" = %.2f / (2 * %.2f) ≃ "BOLDGREEN"%.2f\n"RESET, coefs.b, coefs.a, x0);
		} else {
			float k = -delta;
			printf(BOLDWHITE"Δ < 0 -> No solution in R, but two solutions in C: \n"RESET);
			printf(BOLDWHITE"Let Δ = -k with k > 0. Then,\n\tsqrt(Δ) = sqrt(-k) = i * sqrt(k)\n");
			printf("where "BOLDYELLOW"i"BOLDWHITE" is the imaginary unit such as "BOLDYELLOW"i^2 = -1"BOLDWHITE"\nand "BOLDYELLOW"k"BOLDWHITE" = %.2f\n", k);
			printf("This gives two complex conjugate solutions:\n");
			printf(BOLDMAGENTA"\tx1"RESET" = "BOLDYELLOW"(-b - (i * sqrt(k))) / 2a"RESET" = "BOLDGREEN"(%.2f - i * %.2f) / 2 * %.2f\n"RESET, coefs.b, ft_sqrt(k) ,coefs.a);
			printf(BOLDMAGENTA"\tx2"RESET" = "BOLDYELLOW"(-b + (i * sqrt(k))) / 2a"RESET" = "BOLDGREEN"(%.2f + i * %.2f) / 2 * %.2f\n"RESET, coefs.b, ft_sqrt(k), coefs.a);
		}
	}
	return (0);
}