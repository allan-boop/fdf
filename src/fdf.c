/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:53:38 by ahans             #+#    #+#             */
/*   Updated: 2024/01/21 18:22:39 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <fcntl.h>

#define WIDTH 2560
#define HEIGHT 1440

int	put_line_in_node(char *line, t_map_line *node)
{
	char	**points;
	int		i;

	i = 0;
	points = ft_split(line, ' ');
	node->points = malloc(sizeof(int32_t) * ft_strlen(line));
	while (points[i] != NULL)
	{
		node->points[i] = ft_atoi(points[i]);
		i++;
	}
	i = 0;
	while (points[i] != NULL)
	{
		free(points[i]);
		i++;
	}
	free(points);
	return (EXIT_SUCCESS);
}

t_map_line	*put_map_in_struct(char *filename)
{
	t_map_line	*line;
	int			file;
	t_map_line	*first_line;
	char		*str;

	file = open(filename, O_RDONLY);
	if (!file)
		return (NULL);
	str = get_next_line(file);
	line = malloc(sizeof(t_map_line));
	if (!line)
		return (NULL);
	first_line = line;
	while (str != NULL)
	{
		line->next = malloc(sizeof(t_map_line));
		if (!line->next)
			return (NULL);
		line = line->next;
		put_line_in_node(str, line);
		free(str);
		str = get_next_line(file);
	}
	line->next = NULL;
	close(file);
	return (first_line);
}

int32_t	main(int ac, char **av)
{
//	t_map_line	*tmp;
	t_map_line	*curr;

	ac = ac;
	curr = put_map_in_struct(av[1]);
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		return (EXIT_FAILURE);
	mlx_image_t* img = mlx_new_image(mlx, 2560, 1440);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (EXIT_FAILURE);
	ft_memset(img->pixels, 127, 2560 * 4899);
	mlx_loop(mlx);
	free(curr);
/*	while (curr != NULL)
	{
		tmp = curr->next;
		free(curr->points);
		free(curr);
		curr = tmp;
	}*/
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
