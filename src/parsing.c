/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:56:49 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/29 22:12:56 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

static void add_to_list(char *coefficient, char *exponent, t_polynomial *terms) {
	if (strchr(coefficient, '.') == 0)
		ft_lstadd_back(&terms, ft_lstnew(atof(coefficient), atoi(exponent)));
	else
		ft_lstadd_back(&terms, ft_lstnew(atoi(coefficient), atoi(exponent)));
}

char	*parse_argument(char *argv, t_polynomial *terms)
{
	int i;
	char coefficient[9];
	char exponent[9];
	int j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[i] && argv[i] >= '0' && argv[i] <= '9')
			coefficient[j++] = argv[i++];
		while (argv[i] && (argv[i] < '0' || argv[i] > '9'))
			i++;
		j = 0;
		while (argv[i] && (argv[i] >= '0' && argv[i] <= '9'))
			exponent[j++] = argv[i++];
		add_to_list(coefficient, exponent, terms);
		bzero(coefficient, 9);
		bzero(exponent, 9);
		while (argv[i] && argv[i] < '0' && argv[i] > '9')
			i++;
	}
	return (NULL);
}


// "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"