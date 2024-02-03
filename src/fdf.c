/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:56:47 by ahans             #+#    #+#             */
/*   Updated: 2024/02/03 23:05:06 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

void	draw_map(t_var_stock *map, mlx_image_t *img)
{
	int	i;

	i = 0;
	while (i < (map[0].line_size * map[0].line_count - 1))
	{
		if ((i + 1) % map[0].line_size != 0)
			draw(map[i], map[i + 1], img);
		if (i < (map[0].line_size * map[0].line_count - map[0].line_size))
			draw(map[i], map[i + map[0].line_size], img);
		i++;
	}
}

static void	free_everythings(t_var_stock *array)
{
	int	i;
	int	len;

	i = 0;
	len = array[0].line_size * array[0].line_count;
	while (i < len)
	{
		free(array[i].color);
		i++;
	}
	free(array);
}

int32_t	main(int ac, char **av)
{
	t_var_stock	*vars;
	mlx_image_t	*img;
	mlx_t		*mlx;
	t_hook_pos	*hook;

	mlx = NULL;
	hook = malloc(sizeof(t_hook_pos));
	if (ac != 2)
		return (EXIT_FAILURE);
	vars = NULL;
	put_map_in_tabs(av[1], &vars);
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!mlx)
		return (EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (EXIT_FAILURE);
	rotation_x(vars, vars[0].line_size * vars[0].line_count, 0);
	rotation_y(vars, vars[0].line_size * vars[0].line_count, 0);
	rotation_z(vars, vars[0].line_size * vars[0].line_count, 0);
	recalcul_center(vars);
	draw_map(vars, img);
	hook->mlx = mlx;
	hook->img = img;
	hook->vars = vars;
	mlx_loop_hook(mlx, &ft_hook, hook);
	mlx_loop(mlx);
	free_everythings(vars);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
