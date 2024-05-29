/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:02:16 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/29 21:04:54 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void print_error(char *error_msg) {
	write(2, error_msg, strlen(error_msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}