/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:56:49 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/30 18:05:28 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

static void add_to_list(char *term, char sign, t_polynomial *lst_terms) {
	double coefficient = 0.0;
	int exponent = 0;
	
	while (*term && ((*term > 9 && *term < 13) || *term == 32))
		term++;
	coefficient = (strchr(term, '.')) ? atof(term) : atoi(term);
	(*term == 'X') ? coefficient = 1 : 0;
	// printf("Coefficient =  %f\n", coefficient);
	term = strchr(term, 'X');
	if (term) {
		exponent = atoi(term + 2);
		(!is_digit(*(term + 2))) ? exponent = 1 : 0;
		// (exponent > 2 || exponent < 0) ? printf("Wrong exponent\n") : 0;
		// printf("Exponent = %d\n\n\n", exponent);
	} else {
		// printf("Exponent = %d\n\n\n", exponent);
	}
	ft_lstadd_back(&lst_terms, ft_lstnew(coefficient, exponent, sign, 0));
}


char	*parse_argument(char *argv, t_polynomial *lst_terms)
{
	char	*parts[2];
	char	*term;
	char	*copy;
	char	sign;

	parts[0] = strtok(argv, "=");
	parts[1] = strtok(NULL, "=");
	for (int i = 0; i < 2; i++) {
		sign = '+';
		while (*parts[i] && ((*parts[i] > 9 && *parts[i] < 13) || *parts[i] == 32))
			parts[i]++;
		if (!(copy = strdup(parts[i])))
			return (NULL);
		term = strtok(parts[i], "+-");
		(copy[0] == '-') ? sign = '-' : 0;
		while (term) {
			int from = term - parts[i] + strlen(term);
			// printf("Term = %s    Sign = %c\n", term, sign);
			add_to_list(term, sign, lst_terms);
			term = strtok(NULL, "+-");
			sign = *(copy + from);
		}
		free(copy);
		(i == 0) ? ft_lstadd_back(&lst_terms, ft_lstnew(0, 0, '+', 1)) : 0;
		// (i == 0) ? printf("=\n\n\n") : 0;
	}
	return (NULL);
}


// "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
// "5 + 4 * X + X^2= X^2"