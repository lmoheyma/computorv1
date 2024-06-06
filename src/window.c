/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:24:38 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/06/06 16:30:36 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free_all(data->terms, data->lt, data->rt);
    free(data->mlx);
    exit(EXIT_SUCCESS);
}

double f(double x, t_coef coefs) {
    return (coefs.a * (x * x) + (coefs.b * x) + coefs.c);
}

void put_pixel(t_data *data, int x, int y, int color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        char *dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
        *(unsigned int*)dst = color;
    }
}

void draw_axes(t_data *data) {
    int i;

    for (i = 0; i < WIDTH; i++)
        put_pixel(data, i, HEIGHT / 2, 0xFFFFFF);
    for (i = 0; i < HEIGHT; i++)
        put_pixel(data, WIDTH / 2, i, 0xFFFFFF);
}

void draw_function(t_data *data, t_coef coefs) {
    int x_pixel;
    double x, y;
    int y_pixel;

    for (x_pixel = 0; x_pixel < WIDTH; x_pixel++) {
        x = (x_pixel - WIDTH / 2) / (50 - data->x_offset);
        y = f(x, coefs);
        y_pixel = HEIGHT / 2 - (int)(y * 50 + data->y_offset);

        if (y_pixel >= 0 && y_pixel < HEIGHT)
            put_pixel(data, x_pixel, y_pixel, 0x88FF88);
    }
}

int handle_key(int key, t_data *data) {
    if (key == ESC_KEY) {
        mlx_destroy_window(data->mlx, data->win);
        mlx_destroy_display(data->mlx);
        free_all(data->terms, data->lt, data->rt);
        free(data->mlx);
        exit(EXIT_SUCCESS);
    }
    return (0);
}

int init_window(t_coef coefs, t_polynomial *terms, t_polynomial *left_terms, t_polynomial *right_terms) {
    t_data data;

    if (!(data.mlx = mlx_init())) {
        free_all(terms, left_terms, right_terms);
        exit(EXIT_SUCCESS);
    }
    if (!(data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Function Plotter"))) {
        free_all(terms, left_terms, right_terms);
        exit(EXIT_SUCCESS);
    }
    data.x_offset = 0.0;
    data.y_offset = 0.0;
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);
    
    data.terms = terms;
    data.lt = left_terms;
    data.rt = right_terms;
    data.coefs = coefs;

    draw_axes(&data);
    draw_function(&data, coefs);

    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
    mlx_destroy_image(data.mlx, data.img);

    mlx_key_hook(data.win, handle_key, &data);
    mlx_hook(data.win, 17, 0, close_window, &data);

    mlx_loop(data.mlx);
    
    return (0);
}