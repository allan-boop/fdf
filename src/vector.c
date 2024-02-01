/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:07:07 by ahans             #+#    #+#             */
/*   Updated: 2024/01/31 19:51:58 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_pixel(void *mlx_ptr, int32_t x, int32_t y, int32_t color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	mlx_put_pixel(mlx_ptr, x, y, color);
}

void	draw(t_var_stock current, t_var_stock next, void *image)
{
	int dy;
	int dx;
	int inc_y;
	int inc_x;
	int	slope;
	int	error;
	int	inc_e;
	int	p;

	dy = next.y - current.y;
	dx = next.x - current.x;
	inc_y = 1;
	inc_x = 1;
	if (dy < 0)
	{
		inc_y = -1;
		dy *= -1;
	}
	if (dx < 0)
	{
		inc_x = -1;
		dx *= -1;
	}
	if (dy == 0)
	{
		p = 0;
		while ((int)current.x != (int)next.x + inc_x)
		{
			draw_pixel(image, current.x, current.y, 0xFF0000FF);
			current.x += inc_x;
			p++;
		}
	}
	else if (dx == 0)
	{
		p = 0;
		while ((int)current.y != (int)next.y + inc_y)
		{
			draw_pixel(image, current.x, current.y, 0xFF0000FF);
			current.y += inc_y;
		}
	}
	else if (dx >= dy)
	{
		p = 0;
		slope = dy << 1;
		error = -(dx);
		inc_e = error << 1;
		while ((int)current.x != (int)next.x + inc_x)
		{
			draw_pixel(image, current.x, current.y, 0xFF0000FF);
			error += slope;
			if (error >= 0)
			{
				current.y += inc_y;
				error += inc_e;
			}
			current.x += inc_x;
			p++;
		}
	}
	else
	{
		p = 0;
		slope = dx << 1;
		error = -(dy);
		inc_e = error << 1;
		while ((int)current.y != (int)next.y + inc_y)
		{
			draw_pixel(image, current.x, current.y, 0xFF0000FF);
			error += slope;
			if (error >= 0)
			{
				current.x += inc_x;
				error += inc_e;
			}
			current.y += inc_y;
			p++;
		}
	}
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
	p = 2 * (dy - dx);
	while (x <= (map2.x * ratio + map.start_x))
	{
		if (p >= 0)
		{
			y = y + 1;
			p = p + ((2 * dy) - (2 * dx));
		}
		else
			p = p + (2 * dy);
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
	p = 2 * (dx - dy);
	while (y <= (map2.y * ratio + map.start_y))
	{
		if (p >= 0)
		{
			x = x + 1;
			p = p + ((2 * dx) - (2 * dy));
		}
		else
			p = p + (2 * dx);
		draw_pixel(img, x, y, 0x00AAAAFF);
		y = y + 1;
	}
}



