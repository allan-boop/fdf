/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:07:07 by ahans             #+#    #+#             */
/*   Updated: 2024/01/31 16:20:11 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_pixel(void *mlx_ptr, int32_t x, int32_t y, int32_t color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	mlx_put_pixel(mlx_ptr, x, y, color);
}

void	draw_line(t_var_stock map, t_var_stock map2, void *img, int32_t ratio)
{
	int32_t	dx;
	int32_t	dy;
	int32_t	p;
	int32_t	x;
	int32_t	y;

	dx = (map2.x - map.x) * ratio;
	dy = (map2.y - map.y) * ratio;
	x = (map.x * ratio) + map.start_x;
	y = (map.y * ratio) + map.start_y;
	p = 2 * dy - dx;
	while (x <= (map2.x * ratio + map.start_x))
	{
		if (p >= 0)
		{
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
			p = p + 2 * dy;
		draw_pixel(img, x, y, 0xFF0000FF);
		x = x + 1;
	}
}

void	draw_col(t_var_stock map, t_var_stock map2, void *img, int32_t ratio)
{
	int32_t	dx;
	int32_t	dy;
	int32_t	p;
	int32_t	x;
	int32_t	y;

	dx = (map2.x - map.x) * ratio;
	dy = (map2.y - map.y) * ratio;
	x = (map.x * ratio) + map.start_x;
	y = (map.y * ratio) + map.start_y;
	p = 2 * dx - dy;
	while (y <= (map2.y * ratio + map.start_y))
	{
		if (p >= 0)
		{
			x = x + 1;
			p = p + 2 * dx - 2 * dy;
		}
		else
			p = p + 2 * dx;
		draw_pixel(img, x, y, 0x00AAAAFF);
		y = y + 1;
	}
}
