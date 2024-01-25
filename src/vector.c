/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   vector.c	   :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: ahans <ahans@student.42.fr>	+#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2024/01/25 12:22:30 by ahans	 #+#	#+#	 */
/*   Updated: 2024/01/25 18:23:21 by ahans	###   ########.fr	   */
/*	*/
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
	int		steep;
	int		xstep, ystep;

	steep = 0;
	dx = (map2.x * ratio) - (map.x * ratio);
	dy = (map2.y * ratio) - (map.y * ratio);
	if (abs(dy) > abs(dx))
	{
		int temp = dx;
		dx = dy;
		dy = temp;
		steep = 1;
	}
	if (dx < 0)
	{
		dx = -dx;
		xstep = -1;
	}
	else
	{
		xstep = 1;
	}
	if (dy < 0)
	{
		dy = -dy;
		ystep = -1;
	}
	else
	{
		ystep = 1;
	}
	x = (map.x * ratio) + 5;
	y = (map.y * ratio) + 5;
	p = 2 * dy - dx;
	while (x != ((map2.x * ratio) + 5))
	{
		if (p >= 0)
		{
			y = y + ystep;
			p = p + 2 * dy - 2 * dx;
		}
		else
			p = p + 2 * dy;
		x = x + xstep;
		if (steep)
			draw_pixel(img, y, x, 0xFF0000FF);
		else
			draw_pixel(img, x, y, 0xFF0000FF);
	}
}
