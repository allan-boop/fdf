/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:54:03 by ahans             #+#    #+#             */
/*   Updated: 2024/01/31 19:02:04 by ahans            ###   ########.fr       */
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

void	draw_line(t_var_stock map, t_var_stock map2, void *img, int32_t ratio);
void	draw_col(t_var_stock map, t_var_stock map2, void *img, int32_t ratio);
void	rotation_x(t_var_stock *coord, int size, int angle);
void	rotation_y(t_var_stock *coord, int size, int angle);
void	rotation_z(t_var_stock *coord, int size, int angle);
void	draw(t_var_stock current, t_var_stock next, void *image);

#endif
