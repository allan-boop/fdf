/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:54:03 by ahans             #+#    #+#             */
/*   Updated: 2024/02/01 13:59:32 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include "MLX42.h"
# include <math.h>
# include <fcntl.h>

# define WIDTH 3000
# define HEIGHT 1500

typedef struct s_var_stock
{
	double				x;
	double				y;
	double				z;
	int32_t				start_x;
	int32_t				start_y;
	int32_t				r;
	int32_t				g;
	int32_t				b;
	int32_t				a;
	int32_t				line_size;
	int32_t				line_count;
}	t_var_stock;

typedef struct s_bres
{
	int32_t				dx;
	int32_t				dy;
	int32_t				inc_x;
	int32_t				inc_y;
	mlx_image_t			*img;
}	t_bres;

void	rotation_x(t_var_stock *coord, int size, int angle);
void	rotation_y(t_var_stock *coord, int size, int angle);
void	rotation_z(t_var_stock *coord, int size, int angle);
void	draw(t_var_stock current, t_var_stock next, void *image);
void	draw_pixel(void *mlx_ptr, int32_t x, int32_t y, int32_t color);
int		max(int a, int b);
void	calcul_center(t_var_stock *array);
int		put_map_in_tabs(char *filename, t_var_stock **vars);


#endif
