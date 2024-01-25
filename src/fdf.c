/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   fdf.c	  :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: ahans <ahans@student.42.fr>	+#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2024/01/24 17:46:59 by ahans	 #+#	#+#	 */
/*   Updated: 2024/01/25 12:40:22 by ahans	###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

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
	return (nb_strs - 1);
}

int	get_color(char *str, int rgb, int i)
{
	int	j;
	int	r;

	r = 0;
	while (str[i] != 'x' && str[i] != '\0')
		i++;
	if (str[i] && str[i])
		i++;
	j = i + rgb;
	while (i < j && str[i] != '\0')
		i++;
	j = i + 2;
	while (i != j && str[i] != '\0')
	{
		r = r * 16;
		if (str[i] >= '0' && str[i] <= '9')
			r += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			r += str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			r += str[i] - 'a' + 10;
		i++;
	}
	return (r);
}

int	put_line_in_tab(char *a_line, t_var_stock *vars, int *j)
{
	char	**points;
	int		i;

	i = 0;
	points = ft_split(a_line, ' ');
	while (points[i + 1] != NULL)
	{
		vars[*j].z = ft_atoi(points[i]);
		vars[*j].x = i;
		vars[*j].y = *j / vars[0].line_size;
		vars[*j].r = get_color(points[i], 0, 0);
		vars[*j].g = get_color(points[i], 2, 0);
		vars[*j].b = get_color(points[i], 4, 0);
		vars[*j].a = 255;
		vars[*j].line_size = vars[0].line_size;
		vars[*j].line_count = vars[0].line_count;
		free(points[i]);
		i++;
		*j += 1;
	}
	free(points[i]);
	free(points);
	return (0);
}

int	get_nb_lines(char *filename)
{
	int		file;
	char	*str;
	int		i;

	i = 0;
	file = open(filename, O_RDONLY);
	if (!file)
		return (0);
	str = get_next_line(file);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(file);
		i++;
	}
	close(file);
	return (i);
}

int	put_map_in_tabs(char *filename, t_var_stock **vars)
{
	int			file;
	char		*str;
	int			i;

	file = open(filename, O_RDONLY);
	if (!file)
		return (1);
	str = get_next_line(file);
	*vars = calloc(((get_nb_strs(str, ' '))
				* get_nb_lines(filename)), sizeof(t_var_stock));
	i = 0;
	(*vars[i]).line_size = get_nb_strs(str, ' ');
	(*vars[i]).line_count = get_nb_lines(filename);
	while (str != NULL)
	{
		put_line_in_tab(str, *vars, &i);
		free(str);
		str = get_next_line(file);
	}
	close(file);
	return (0);
}

void draw_map(t_var_stock *map, mlx_image_t *img)
{
	int	i;

	i = 0;
	while (i < (map[0].line_size * map[0].line_count) - 1)
	{
			draw_line(map[i], map[i + 1], img, 20);
		i++;
	}
	draw_line(map[0], map[1], img, 20);
}

int32_t	main(int ac, char **av)
{
	t_var_stock	*vars;
	mlx_image_t	*img;
	mlx_t		*mlx;

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
	for (int j = 0; j < 1920; j++)
	{
		for (int i = 0; i < 1080 - 1 ; i++)
		{
			mlx_put_pixel(img, j, i, 0x000000FF);
		}
	}
	draw_map(vars, img);
	free(vars);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
