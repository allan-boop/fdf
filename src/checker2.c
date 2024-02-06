/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:45:16 by ahans             #+#    #+#             */
/*   Updated: 2024/02/06 19:26:43 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	verif_1(char *str, t_var_stock *array)
{
	free(str);
	while (array[0].i < array[0].j)
	{
		free(array[array[0].i].color);
		(array[0].i)++;
	}
	free(array);
	perror("Malloc error.\n");
	exit (EXIT_FAILURE);
}

void	verif_2(char *str, t_var_stock *array)
{
	free(str);
	array[0].i = 0;
	while (array[0].i < array[0].j)
	{
		free(array[array[0].i].color);
		(array[0].i)++;
	}
	free(array);
	perror("Bad digit.\n");
	exit (EXIT_FAILURE);
}

void	verif_3(char *str, t_var_stock *array)
{
	if (!array[array[0].j].color)
	{
		array[0].i = 0;
		free(str);
		while (array[0].i < array[0].j)
		{
			free(array[array[0].i].color);
			(array[0].i)++;
		}
		free(array);
		perror("Malloc error, transparent line.\n");
		exit (EXIT_FAILURE);
	}
}

void	verif_4(t_var_stock *array, char **points)
{
	if (!array[array[0].j].color)
	{
		while (points[array[0].i])
		{
			free(points[array[0].i]);
			(array[0].i)++;
		}
		free(points);
	}
}

void	verif_5(t_var_stock *array)
{
	if (array[0].i != array[0].line_size)
	{
		array[0].i = 0;
		while (array[0].i < array[0].j)
		{
			free(array[array[0].i].color);
			(array[0].i)++;
		}
		free(array);
		perror("Bad line.\n");
		exit (EXIT_FAILURE);
	}
}
