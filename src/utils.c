/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:31:39 by ahans             #+#    #+#             */
/*   Updated: 2024/02/05 10:52:33 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_pixel(void *mlx_ptr, int32_t x, int32_t y, int32_t color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	mlx_put_pixel(mlx_ptr, x, y, color);
}

static double	median_x(t_var_stock *array, int size)
{
	double	median;
	int		i;

	i = 0;
	median = 0;
	while (i < size)
	{
		median += array[i].x;
		i++;
	}
	return (median / size);
}

static double	median_y(t_var_stock *array, int size)
{
	double	median;
	int		i;

	i = 0;
	median = 0;
	while (i < size)
	{
		median += array[i].y;
		i++;
	}
	return (median / size);
}

void	recalcul_center(t_var_stock *array)
{
	int		i;
	double	med_x;
	double	med_y;

	i = 0;
	med_x = median_x(array, array[0].line_count * array[0].line_size);
	med_y = median_y(array, array[0].line_count * array[0].line_size);
	while (array[0].line_count * array[0].line_size > i)
	{
		array[i].x = (array[i].x - med_x) + (WIDTH / 2);
		array[i].y = (array[i].y - med_y) + (HEIGHT / 2);
		i++;
	}
}
