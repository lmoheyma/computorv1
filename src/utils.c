/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:02:16 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/06/01 16:26:07 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

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
	fprintf(stderr, BOLDRED"%s\n"RESET, error_msg);
	exit(EXIT_FAILURE);
}