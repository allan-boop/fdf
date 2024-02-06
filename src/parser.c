/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   parser.c	   :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: ahans <ahans@student.42.fr>	+#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2024/02/01 13:56:42 by ahans	 #+#	#+#	 */
/*   Updated: 2024/02/05 16:56:23 by ahans	###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_free_points(char **points, t_var_stock *array)
{
	while (points[array[0].i])
	{
		free(points[array[0].i]);
		(array[0].i)++;
	}
	free(points);
}

unsigned int	get_nb_strs(char const *s, char c)
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

static void	core_put_in_tab(t_var_stock *array, char **points, char *str)
{
	if (array[0].j < array[0].len_total)
	{
		array[array[0].j].z = ft_atoi(points[array[0].i])
			* array[0].height_of_z;
		array[array[0].j].x = (array[0].i) * array[0].zoom;
		array[array[0].j].y = (array[0].j / array[0].line_size) * array[0].zoom;
		array[array[0].j].color = ft_strlower(get_color(points[array[0].i]));
		if (array[array[0].j].color == NULL)
		{
			if (array[array[0].j].z > 0)
			{
				array[array[0].j].color = ft_strdup("ff00ffff");
				verif_4(array, points);
				verif_3(str, array);
			}
			else
			{
				array[array[0].j].color = ft_strdup("ff3070ff");
				verif_4(array, points);
				verif_3(str, array);
			}
		}
		(array[0].j)++;
	}
}

static int	put_line_in_tab(char *str, t_var_stock *array)
{
	char	**points;
	int		i;

	points = ft_split(str, ' ');
	if (!points)
		verif_1(str, array);
	array[0].i = 0;
	while (points[array[0].i] != NULL)
	{
		i = 0;
		while (points[array[0].i][i] == '-' || points[array[0].i][i] == '+')
			i++;
		if (ft_isdigit(points[array[0].i][i]) == 0)
		{
			ft_free_points(points, array);
			verif_2(str, array);
		}
		core_put_in_tab(array, points, str);
		free(points[array[0].i]);
		(array[0].i)++;
	}
	free(points[array[0].i]);
	free(points);
	verif_5(array);
	return (0);
}

int	put_map_in_tabs(char *fdname, t_var_stock **array)
{
	int			fd;
	char		*str;

	fd = check_fd(fdname);
	str = get_next_line(fd);
	check_gnl(str);
	*array = ft_calloc(((get_nb_strs(str, ' '))
				* get_nb_lines(fdname)), sizeof(t_var_stock));
	if (!*array)
	{
		free(str);
		close(fd);
		exit (EXIT_FAILURE);
	}
	give_value(*array, str, fdname);
	while (str != NULL)
	{
		put_line_in_tab(str, *array);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
