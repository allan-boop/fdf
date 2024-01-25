/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:22:30 by ahans             #+#    #+#             */
/*   Updated: 2024/01/25 15:56:33 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_pixel(void *mlx_ptr, int32_t x, int32_t y, int32_t color)
{
	mlx_put_pixel(mlx_ptr, x, y, color);
}

void	draw_line(t_var_stock map, t_var_stock map2, void *img, int32_t ratio)
{
	int32_t	dx;
	int32_t	dy;
	int32_t	p;
	int32_t	x;
	int32_t	y;

	map = map;
	dx = (map2.x * ratio) - (map.x * ratio);
	dy = (map2.y * ratio) - (map.y * ratio);
	x = (map.x * ratio) + 5;
	y = (map.y * ratio) + 5;
	p = 2 * dy - dx;
	while (x < ((map2.x * ratio) + 5))
	{
		if (p >= 0)
		{
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
			p = p + 2 * dy;
		x = x + 1;
		draw_pixel(img, x, y, 0x00AAAAFF);
	}
}
