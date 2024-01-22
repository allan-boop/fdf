/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:53:38 by ahans             #+#    #+#             */
/*   Updated: 2024/01/22 16:06:13 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <fcntl.h>

#define WIDTH 1920
#define HEIGHT 1080

static unsigned int	get_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

int	put_line_in_node(char *line, t_map_line *node)
{
	char	**points;
	int		i;

	i = 0;
	points = ft_split(line, ' ');
	node->points = malloc(sizeof(int32_t) * get_nb_strs(line, ' '));
	node->length = get_nb_strs(line, ' ') - 1;
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
	put_line_in_node(str, line);
	first_line = line;
	free(str);
	str = get_next_line(file);
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
	t_map_line		*tmp;
	t_map_line		*curr;
	mlx_image_t		*img;
	mlx_t			*mlx;

	ac = ac;
	curr = put_map_in_struct(av[1]);

	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		return (EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (EXIT_FAILURE);
	for (int j = 0; j < 1920; j++)
	{
		for (int i = 0; i < 1080 - 1 ; i++)
		{
			if (i % 10 == 0)
				mlx_put_pixel(img, j, i, 0x00CC0000);
			else
				mlx_put_pixel(img, j, i, 0x85A1DDAA);
		}
	}
	mlx_loop(mlx);
	while (curr != NULL)
	{
		tmp = curr->next;
		free(curr->points);
		free(curr);
		curr = tmp;
	}
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
