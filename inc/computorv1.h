/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:23:43 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/05/30 20:54:06 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_polynomial
{
	char				sign;
	float				coefficient;
	int					exponent;
	int					separator;
	struct s_polynomial	*next;
}						t_polynomial;

typedef struct s_coef {
	float a;
	float b;
	float c;
} t_coef;

// Handle errors
void					print_error(char *error_msg);

// List utils
void					ft_lstadd_back(t_polynomial **lst, t_polynomial *new);
t_polynomial			*ft_lstnew(float coefficient, int exponent, char sign,
							int flag);
int						ft_lstsize(t_polynomial *lst);
void					print_lst(t_polynomial *terms);
t_polynomial			*ft_lstlast(t_polynomial *lst);
void					split_list(t_polynomial **terms,
							t_polynomial **left_terms,
							t_polynomial **right_terms);
void					free_list(t_polynomial *terms);

// Parsing equation
char					*parse_argument(char *argv, t_polynomial **lst_terms);

// Parsing utils
int						is_digit(char c);

// Solving equation
void 					reduce_equation(t_polynomial *left_terms, t_polynomial *right_terms);

// Free
void					free_all(t_polynomial *terms, t_polynomial *left_terms,
							t_polynomial *right_terms);

#endif