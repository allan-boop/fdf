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

static void	default_color(t_var_stock *vars, int *j, char *a_line, char **points, int i)
{
	if (vars[*j].z > 0)
	{
		vars[*j].color = ft_strdup("ff00ffff");
		if (!vars[*j].color)
		{
			free(a_line);
			free(points[i]);
			free(points);
			while (i < *j)
			{
				free(vars[i].color);
				i++;
			}
			free(vars);
			perror("Malloc error, transparent line.\n");
			exit (EXIT_FAILURE);
		}
	}
	else
	{
		vars[*j].color = ft_strdup("ff3070ff");
		if (!vars[*j].color)
		{
			free(a_line);
			free(points[i]);
			free(points);
			while (i < *j)
			{
				free(vars[i].color);
				i++;
			}
			free(vars);
			perror("Malloc error, transparent line.\n");
			exit (EXIT_FAILURE);
		}
	}
}

static int	put_line_in_tab(char *a_line, t_var_stock *vars, int *j)
{
	char	**points;
	int		i;

	i = 0;
	points = ft_split(a_line, ' ');
	if (points == NULL)
	{
		free(a_line);
		free(vars);
		perror("malloc error");
		exit (EXIT_FAILURE);
	}
	while (points[i] != NULL)
	{
		if (ft_isdigit(points[i][0]) == 0)
		{
			free(points);
			free(a_line);
			while (i < *j)
			{
				free(vars[*j].color);
				i++;
			}
			free(vars);
			perror("Bad digit.\n");
			exit (EXIT_FAILURE);
		}
		if (*j < vars[0].line_size * vars[0].line_count)
		{
			vars[*j].z = (ft_atoi(points[i]) * 10);
			vars[*j].x = (i * 1);
			vars[*j].y = ((*j / vars[0].line_size) * 1);
			vars[*j].color = ft_strlower(get_color(points[i]));
			if (vars[*j].color == NULL)
				default_color(vars, j, a_line, points, i);
			*j += 1;
		}
		free(points[i]);
		i++;
	}
	free(points[i]);
	free(points);
	if (i != vars[0].line_size)
	{
		i = 0;
		while (i < *j)
		{
			i++;
		}
		free(vars);
		perror("map error");
		exit (EXIT_FAILURE);
	}
	return (0);
}

static int	get_nb_lines(char *filename)
{
	int		file;
	char	*str;
	int		i;

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

int	put_map_in_tabs(char *filename, t_var_stock **vars)
{
	int32_t		file;
	char		*str;
	int			i;
	int			nb_strs;
	int			nb_lines;

	file = check_fd(filename);
	str = get_next_line(file);
	check_gnl(str);
	nb_strs = get_nb_strs(str, ' ');
	nb_lines = get_nb_lines(filename);
	if (nb_strs == 0 || nb_lines == 0)
	{
		free(str);
		close(file);
		exit (EXIT_FAILURE);
	}
	*vars = ft_calloc((nb_strs * nb_lines), sizeof(t_var_stock));
	if (*vars == NULL)
	{
		free(str);
		close(file);
		exit (EXIT_FAILURE);
	}
	i = 0;
	(*vars[i]).line_size = nb_strs;
	(*vars[i]).line_count = nb_lines;
	while (str != NULL)
	{
		put_line_in_tab(str, *vars, &i);
		free(str);
		str = get_next_line(file);
	}
	close(file);
	return (0);
}
