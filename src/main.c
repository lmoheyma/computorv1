/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:25:44 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/06/01 17:28:39 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

int main(int argc, char **argv) {
	int display = 0;
	t_polynomial *terms = NULL;
	t_polynomial *left_terms = NULL;
	t_polynomial *right_terms = NULL;
	
	if (argc > 3)
		print_error("Wrong number of arguments");
	if (argv[2] && strcmp(argv[2], "-d") == 0) display = 1;
	if ((parse_argument(argv[1], &terms)))
		return (print_error("Invalid syntax"), free_all(terms, left_terms, right_terms), 1);
	split_list(&terms, &left_terms, &right_terms);
	if (solve_equation(left_terms, right_terms, terms, display))
		return (free_all(terms, left_terms, right_terms), 1);
	free_all(terms, left_terms, right_terms);
	return (0);
}