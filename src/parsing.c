/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:56:49 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/31 00:02:31 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

static int is_accepted_char(char c) {
	return (c == '.' || c == '+' || c == '-'
			|| ((c >= 9 && c <= 13) || c == 32)
			|| c == '*' || c == 'X' || c == '^'
			|| c == '=');
}

static int check_invalid_syntax(char *argv) {
	if (!strchr(argv, '='))
		return (1);
	while (*argv) {
		if (!is_digit(*argv) && !is_accepted_char(*argv))
			return (1);
		if (*argv == 'X' && (*(argv + 1) != ' ' && *(argv + 1) != '^'))
			return (1);
		argv++;
	}
	return (0);
}

static void add_to_list(char *term, char sign, t_polynomial **lst_terms) {
	double coefficient = 0.0;
	int exponent = 0;
	
	while (*term && ((*term >= 9 && *term <= 13) || *term == 32))
		term++;
	coefficient = (strchr(term, '.')) ? atof(term) : atoi(term);
	(*term == 'X') ? coefficient = 1 : 0;
	term = strchr(term, 'X');
	if (term) {
		exponent = atoi(term + 2);
		(!is_digit(*(term + 2))) ? exponent = 1 : 0;
	}
	ft_lstadd_back(lst_terms, ft_lstnew(coefficient, exponent, sign, 0));
}

int	parse_argument(char *argv, t_polynomial **lst_terms)
{
	char	*parts[2];
	char	*term;
	char	*copy;
	char	sign;

	if (check_invalid_syntax(argv))
		return (1);
	parts[0] = strtok(argv, "=");
	parts[1] = strtok(NULL, "=");
	for (int i = 0; i < 2; i++) {
		sign = '+';
		while (*parts[i] && ((*parts[i] >= 9 && *parts[i] <= 13) || *parts[i] == 32))
			parts[i]++;
		if (!(copy = strdup(parts[i])))
			return (0);
		term = strtok(parts[i], "+-");
		(copy[0] == '-') ? sign = '-' : 0;
		while (term) {
			int from = term - parts[i] + strlen(term);
			add_to_list(term, sign, lst_terms);
			term = strtok(NULL, "+-");
			sign = *(copy + from);
		}
		free(copy);
		(i == 0) ? ft_lstadd_back(lst_terms, ft_lstnew(0, 0, '+', 1)) : 0;
	}
	return (0);
}
