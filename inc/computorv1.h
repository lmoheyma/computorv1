/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:23:43 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/06/04 20:40:55 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include "colors.h"
#include "mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#define WIDTH 800
#define HEIGHT 600
#define ESC_KEY 65307
#define SCROLL_UP 4
#define SCROLL_DOWN 5
#define M_PI       3.14159265358979323846

typedef struct s_polynomial
{
	char				sign;
	float				coefficient;
	int					exponent;
	int					separator;
	struct s_polynomial	*next;
}						t_polynomial;

typedef struct s_coef
{
	float				a;
	float				b;
	float				c;
}						t_coef;

typedef struct s_data {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bpp;
    int line_length;
    int endian;
    double x_offset;
    double y_offset;
	t_polynomial *terms;
	t_polynomial *lt;
	t_polynomial *rt;
	t_coef coefs;
} t_data;

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
int						parse_argument(char *argv, t_polynomial **lst_terms);

// Parsing utils
int						is_digit(char c);

// Solving equation
int						solve_equation(t_polynomial *left_terms,
							t_polynomial *right_terms, t_polynomial *terms, int display);
int						polynomial_degree(t_polynomial *terms);
float					ft_sqrt(float nb);
float					ft_fabs(float nb);
float					ft_pgcd(float a, float b);

// Free
void					free_all(t_polynomial *terms, t_polynomial *left_terms,
							t_polynomial *right_terms);

// Window
int						init_window(t_coef coefs, t_polynomial *terms, t_polynomial *left_terms,
							t_polynomial *right_terms);

#endif