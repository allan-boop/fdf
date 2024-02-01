/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:31:39 by ahans             #+#    #+#             */
/*   Updated: 2024/02/01 13:55:52 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	draw_pixel(void *mlx_ptr, int32_t x, int32_t y, int32_t color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	mlx_put_pixel(mlx_ptr, x, y, color);
}

void	calcul_center(t_var_stock *array)
{
	int	map_height;
	int	map_width;
	int	start_x;
	int	start_y;
	int	i;

	map_height = (array[0].line_count / array[0].line_size);
	map_width = array[0].line_size;
	start_x = (WIDTH - map_width) / 2;
	start_y = (HEIGHT - map_height) / 2;
	i = 0;
	while (array[0].line_count * array[0].line_size > i)
	{
		array[i].start_x = start_x;
		array[i].start_y = start_y;
		i++;
	}
}
