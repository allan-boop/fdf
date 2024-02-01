/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:56:42 by ahans             #+#    #+#             */
/*   Updated: 2024/02/01 18:24:18 by ahans            ###   ########.fr       */
/*                                                                            */
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

static int	get_color(char *str, int rgb, int i)
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

static int	put_line_in_tab(char *a_line, t_var_stock *vars, int *j)
{
	char	**points;
	int		i;

	i = 0;
	points = ft_split(a_line, ' ');
	calcul_center(vars);
	while (points[i] != NULL)
	{
		vars[*j].z = (ft_atoi(points[i]) * 1);
		vars[*j].x = (i * 20) + vars[0].start_x - (vars[0].line_size * 20 / 2);
		vars[*j].y = ((*j / vars[0].line_size) * 20) \
					+ vars[0].start_y - (vars[0].line_count * 20 / 4);
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

static int	get_nb_lines(char *filename)
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

