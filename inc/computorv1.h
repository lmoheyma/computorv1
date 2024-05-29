/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:23:43 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/29 21:06:22 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
#define COMPUTORV1_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_polynomial {
	int coefficient;
	int exponent;
	struct s_polynomial *next;
} t_polynomial;

// Handle errors
void print_error(char *error_msg);

// List utils
void	ft_lstadd_back(t_polynomial **lst, t_polynomial *new);
t_polynomial	*ft_lstnew(int coefficient, int exponent);
int	ft_lstsize(t_polynomial *lst);


#endif