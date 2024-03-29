/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:56:47 by ahans             #+#    #+#             */
/*   Updated: 2024/02/06 20:41:04 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_map(t_var_stock *map, mlx_image_t *img, float ratio)
{
	int	i;

	i = 0;
	while (i < (map[0].line_size * map[0].line_count))
	{
		map[i].x *= ratio;
		map[i].y *= ratio;
		i++;
	}
	recalcul_center(map);
	i = 0;
	while (i < (map[0].line_size * map[0].line_count - 1))
	{
		if ((i + 1) % map[0].line_size != 0)
		{
			draw(map[i], map[i + 1], img);
		}
		if (i < (map[0].line_size * map[0].line_count - map[0].line_size))
		{
			draw(map[i], map[i + map[0].line_size], img);
		}
		i++;
	}
}

static void	free_everythings(t_var_stock *array, t_hook_pos *hook)
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
	free(hook);
	free(array);
}

int32_t	main(int ac, char **av)
{
	t_var_stock	*vars;
	mlx_image_t	*img;
	mlx_t		*mlx;
	t_hook_pos	*hook;

	if (ac != 2)
		return (EXIT_FAILURE);
	put_map_in_tabs(av[1], &vars);
	hook = malloc(sizeof(t_hook_pos));
	if (!hook)
		return (0);
	create_mlx(&mlx, &img);
	hook->mlx = mlx;
	hook->img = img;
	hook->vars = vars;
	mlx_loop_hook(mlx, &ft_hook, hook);
	mlx_loop(mlx);
	free_everythings(vars, hook);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
