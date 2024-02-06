/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:32:53 by ahans             #+#    #+#             */
/*   Updated: 2024/02/06 20:39:49 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_gnl(char *str)
{
	if (str == NULL)
	{
		perror("empty file");
		exit (EXIT_FAILURE);
	}
}

int32_t	check_fd(char *filename)
{
	int32_t	file;

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		perror("file descriptor error");
		exit (EXIT_FAILURE);
	}
	else if (file == 0)
	{
		perror("file descriptor empty");
		exit (EXIT_FAILURE);
	}
	return (file);
}

void	check_argc(int argc)
{
	if (argc < 2)
	{
		perror("Add map please.");
		exit (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		perror("Too many arguments.");
		exit (EXIT_FAILURE);
	}
}

int32_t	get_nb_lines(char *filename)
{
	int32_t	file;
	char	*str;
	int32_t	i;

	i = 0;
	file = check_fd(filename);
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

void	create_mlx(mlx_t **mlx, mlx_image_t **img)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	*mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!mlx)
		return ;
	*img = mlx_new_image(*mlx, WIDTH, HEIGHT);
	if (!*img || (mlx_image_to_window(*mlx, *img, 0, 0) < 0))
		return ;
}
