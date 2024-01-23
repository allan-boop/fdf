/* ************************************************************************** */
/*			*/
/*		:::	  ::::::::   */
/*   fdf.c			  :+:	  :+:	:+:   */
/*			+:+ +:+		 +:+	 */
/*   By: ahans <ahans@student.42.fr>		+#+  +:+	   +#+		*/
/*		+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/18 15:53:38 by ahans			 #+#	#+#			 */
/*   Updated: 2024/01/23 11:34:32 by ahans			###   ########.fr	   */
/*			*/
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
	return (nb_strs);
}

int	put_line_in_tab(char *a_line, t_var_stock *vars, int j)
{
	char	**points;
	int		i;

	i = 0;
	points = ft_split(a_line, ' ');
	while (points[i] != NULL)
	{
		vars->map[j][i] = ft_atoi(points[i]);
		free(points[i]);
		i++;
	}
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

int	**put_map_in_tabs(char *filename, t_var_stock *vars)
{
	int			file;
	char		*str;
	int			i;

	vars->limit_x = get_nb_lines(filename);
	vars->map = malloc(sizeof(int32_t *) * (vars->limit_x + 1));
	if (!vars->map)
		return (NULL);
	file = open(filename, O_RDONLY);
	if (!file)
		return (NULL);
	str = get_next_line(file);
	vars->limit_y = get_nb_strs(str, ' ') - 1;
	i = 0;
	while (str != NULL)
	{
		vars->map[i] = malloc(sizeof(int32_t) * (vars->limit_y + 1));
		if (!vars->map[i])
		{
			while (i > 0)
			{
				i--;
				free(vars->map[i]);
			}
			free(vars->map);
			free(str);
			close(file);
			return (NULL);
		}
		put_line_in_tab(str, vars, i);
		free(str);
		str = get_next_line(file);
		i++;
	}
	vars->map[i] = NULL;
	close(file);
	return (vars->map);
}

int32_t	clean_map(t_var_stock *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		vars->map[i] = NULL;
		i++;
	}
	free(vars->map);
	free(vars);
	return (0);
}

int32_t	main(int ac, char **av)
{
	t_var_stock	*vars;
	mlx_image_t	*img;
	mlx_t		*mlx;

	if (ac != 2)
		return (EXIT_FAILURE);
	ac = ac;
	vars = malloc(sizeof(t_var_stock));
	put_map_in_tabs(av[1], vars);
	clean_map(vars);
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
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
