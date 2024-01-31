/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:00:52 by ahans             #+#    #+#             */
/*   Updated: 2024/01/31 15:56:35 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotation_x(t_var_stock *coord, int size, int angle)
{
	int		i;
	float	rad;
	float	y;

	if (angle != 0)
	{
		rad = angle * (M_PI / 180);
		i = 0;
		while (i < size)
		{
			y = coord[i].y;
			coord[i].y = (cos(rad) * y) - (sin(rad) * coord[i].z);
			coord[i].z = (sin(rad) * y) + (cos(rad) * coord[i].z);
			i++;
		}
	}
}

void	rotation_y(t_var_stock *coord, int size, int angle)
{
	int		i;
	float	rad;
	float	x;
	float	z;

	if (angle != 0)
	{
		rad = angle * (M_PI / 180);
		i = 0;
		while (i < size)
		{
			x = coord[i].x;
			z = coord[i].z;
			ft_printf("x: %d\n", x);
			coord[i].x = x * cos(rad) + z * sin(rad);
			coord[i].z = -x * sin(rad) + z * cos(rad);
			i++;
		}
	}
}

void	rotation_z(t_var_stock *coord, int size, int angle)
{
	int		i;
	float	rad;
	float	x;

	if (angle != 0)
	{
		i = 0;
		rad = angle * (M_PI / 180);
		while (i < size)
		{
			x = coord[i].x;
			coord[i].x = (cosf(rad) * x) - (sinf(rad) * coord[i].y);
			coord[i].y = (sinf(rad) * x) + (cosf(rad) * coord[i].y);
			i++;
		}
	}
}
