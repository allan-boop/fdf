/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:54:03 by ahans             #+#    #+#             */
/*   Updated: 2024/02/03 23:34:41 by ahans            ###   ########.fr       */
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
	char				*color;
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

typedef struct s_map_size
{
	int32_t				x;
	int32_t				y;
}	t_m_s;

typedef struct s_hook_pos
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			size;
	t_var_stock	*vars;
	int			x;
	int			angle_x;
	int			angle_y;
	int			angle_z;
	float		zoom;
	t_var_stock	center;
}	t_hook_pos;

void	rotation_x(t_var_stock *coord, int size, int angle);
void	rotation_y(t_var_stock *coord, int size, int angle);
void	rotation_z(t_var_stock *coord, int size, int angle);
void	draw(t_var_stock current, t_var_stock next, void *image);
void	draw_pixel(void *mlx_ptr, int32_t x, int32_t y, int32_t color);
int		max(int a, int b);
int		put_map_in_tabs(char *filename, t_var_stock **vars);
void	recalcul_center(t_var_stock *array);
char	*get_color(char *str);
void	ft_hook(void *hook);
void	draw_map(t_var_stock *map, mlx_image_t *img, float ratio);

#endif
