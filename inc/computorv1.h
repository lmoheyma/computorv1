/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:23:43 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/30 15:20:39 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
#define COMPUTORV1_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_polynomial {
	char sign;
	int coefficient;
	int exponent;
	int	separator;
	struct s_polynomial *next;
} t_polynomial;

// Handle errors
void print_error(char *error_msg);

// List utils
void	ft_lstadd_back(t_polynomial **lst, t_polynomial *new);
t_polynomial	*ft_lstnew(int coefficient, int exponent);
int	ft_lstsize(t_polynomial *lst);
void print_lst(t_polynomial *terms);
t_polynomial	*ft_lstlast(t_polynomial *lst);

// Parsing equation
char	*parse_argument(char *argv, t_polynomial *lst_terms);

#endif