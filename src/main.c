/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:25:44 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/30 18:07:54 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

int main(int argc, char **argv) {
	t_polynomial terms;
	char	*error_msg;
	
	if (argc != 2)
		print_error("Wrong number of arguments");
	if ((error_msg = parse_argument(argv[1], &terms)))
		print_error(error_msg);
	printf("LIST TERMS: \n\n\n");
	print_lst(&terms);
	// split_lists(&terms);
}