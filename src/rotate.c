/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:00:52 by ahans             #+#    #+#             */
/*   Updated: 2024/02/02 17:48:31 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotation_x(t_var_stock *coord, int size, int angle)
{
	int		i;
	double	rad;
	double	y;
	double	z;

	if (angle != 0)
	{
		rad = angle * (M_PI / 180);
		i = 0;
		while (i < size)
		{
			y = coord[i].y;
			z = coord[i].z;
			coord[i].y = (y * cos(rad)) - (z * sin(rad));
			coord[i].z = (y * sin(rad)) + (z * cos(rad));
			i++;
		}
	}
}

void	rotation_y(t_var_stock *coord, int size, int angle)
{
	int		i;
	double	rad;
	double	x;
	double	z;

	if (angle != 0)
	{
		rad = angle * (M_PI / 180);
		i = 0;
		while (i < size)
		{
			x = coord[i].x;
			z = coord[i].z;
			coord[i].x = (x * cos(rad)) + (z * sin(rad));
			coord[i].z = (-x * sin(rad)) + (z * cos(rad));
			i++;
		}
	}
}

void	rotation_z(t_var_stock *coord, int size, int angle)
{
	int		i;
	double	rad;
	double	x;
	double	y;

	if (angle != 0)
	{
		i = 0;
		rad = angle * (M_PI / 180);
		while (i < size)
		{
			x = coord[i].x;
			y = coord[i].y;
			coord[i].x = (x * cos(rad)) - (y * sin(rad));
			coord[i].y = (x * sin(rad)) + (y * cos(rad));
			i++;
		}
	}
}
