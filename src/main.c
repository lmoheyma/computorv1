/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:25:44 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/31 18:49:19 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

int main(int argc, char **argv) {
	t_polynomial *terms = NULL;
	t_polynomial *left_terms = NULL;
	t_polynomial *right_terms = NULL;
	
	if (argc != 2)
		print_error("Wrong number of arguments");
	if ((parse_argument(argv[1], &terms)))
		return (print_error("Invalid syntax"), free_all(terms, left_terms, right_terms), 1);
	split_list(&terms, &left_terms, &right_terms);
	// printf("Left terms:\n");
	// print_lst(left_terms);
	// printf("\n\nRight terms:\n");
	// print_lst(right_terms);
	if (solve_equation(left_terms, right_terms, terms))
		return (free_all(terms, left_terms, right_terms), 1);
	free_all(terms, left_terms, right_terms);
	return (0);
}