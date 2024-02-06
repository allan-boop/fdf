/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:07:07 by ahans             #+#    #+#             */
/*   Updated: 2024/02/06 20:12:52 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	bres_y_0(t_var_stock current, t_var_stock next, t_bres bres)
{
	while ((int)current.x != (int)next.x + bres.inc_x)
	{
		draw_pixel(bres.img, current.x, current.y, ft_atoi_base(current.color));
		current.x += bres.inc_x;
	}
}

static void	bres_x_0(t_var_stock current, t_var_stock next, t_bres bres)
{
	while ((int)current.y != (int)next.y + bres.inc_y)
	{
		draw_pixel(bres.img, current.x, current.y, ft_atoi_base(current.color));
		current.y += bres.inc_y;
	}
}

static void	bres_dx_bigger(t_var_stock current, t_var_stock next, t_bres bres)
{
	int	slope;
	int	error;
	int	inc_e;

	slope = bres.dy << 1;
	error = -(bres.dx);
	inc_e = error << 1;
	while ((int)current.x != (int)next.x + bres.inc_x)
	{
		draw_pixel(bres.img, current.x, current.y, ft_atoi_base(current.color));
		error += slope;
		if (error >= 0)
		{
			current.y += bres.inc_y;
			error += inc_e;
		}
		current.x += bres.inc_x;
	}
}

static void	bres_standard(t_var_stock current, t_var_stock next, t_bres bres)
{
	int	slope;
	int	error;
	int	inc_e;

	slope = bres.dx << 1;
	error = -(bres.dy);
	inc_e = error << 1;
	while ((int)current.y != (int)next.y + bres.inc_y)
	{
		draw_pixel(bres.img, current.x, current.y, ft_atoi_base(current.color));
		error += slope;
		if (error >= 0)
		{
			current.x += bres.inc_x;
			error += inc_e;
		}
		current.y += bres.inc_y;
	}
}

void	draw(t_var_stock current, t_var_stock next, void *image)
{
	t_bres	bres;

	bres.dy = next.y - current.y;
	bres.dx = next.x - current.x;
	bres.inc_y = 1;
	bres.inc_x = 1;
	if (bres.dy < 0)
	{
		bres.inc_y = -1;
		bres.dy *= -1;
	}
	if (bres.dx < 0)
	{
		bres.inc_x = -1;
		bres.dx *= -1;
	}
	bres.img = image;
	if (bres.dy == 0)
		bres_y_0(current, next, bres);
	else if (bres.dx == 0)
		bres_x_0(current, next, bres);
	else if (bres.dx >= bres.dy)
		bres_dx_bigger(current, next, bres);
	else
		bres_standard(current, next, bres);
}
