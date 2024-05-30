/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:56:49 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/30 15:44:04 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

// static void add_to_list(char *term, t_polynomial *lst_terms) {
// 	while (*term && ((*term > 9 && *term < 13) || *term == 32))
// 		term++;
// 	if (strchr(term, 'X') == 0) {
		
// 	}
// 	else {
		
// 	}
// 	(void)lst_terms;
// 	// if (strchr(coefficient, '.') == 0)
// 	// 	ft_lstadd_back(&terms, ft_lstnew(atof(coefficient), atoi(exponent)));
// 	// else
// 	// 	ft_lstadd_back(&terms, ft_lstnew(atoi(coefficient), atoi(exponent)));
// }

char	*parse_argument(char *argv, t_polynomial *lst_terms)
{
	char	*parts[2];
	char	*term;
	char	*copy = NULL;
	(void)lst_terms;
	char	sign = '+';

	parts[0] = strtok(argv, "=");
	parts[1] = strtok(NULL, "=");
	for (int i = 0; i < 2; i++) {
		copy = strdup(parts[i]);
		term = strtok(parts[i], "+-");
		(copy[0] == '-') ? sign = '-' : 0;
		while (term) {
			int from = term - parts[i] + strlen(term);
			printf("Term = %s    Sign = %c\n", term, sign);
			term = strtok(NULL, "+-");
			sign = *(copy + from);
			// add_to_list(term, lst_terms);
		}
		free(copy);
		(i == 0) ? printf("=\n") : 0;
	}
	
	return (NULL);
}


// "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
// "5 + 4 * X + X^2= X^2"