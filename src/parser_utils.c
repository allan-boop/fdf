/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:20:52 by ahans             #+#    #+#             */
/*   Updated: 2024/02/06 20:17:27 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	give_value(t_var_stock *array, char *str, char *fdname)
{
	double	widt;
	double	heigh;

	array[0].line_size = get_nb_strs(str, ' ');
	array[0].line_count = get_nb_lines(fdname);
	array[0].len_total = array[0].line_size * array[0].line_count;
	array[0].height_of_z = 5;
	widt = HEIGHT / array[0].line_size;
	heigh = WIDTH / array[0].line_count;
	if (widt < heigh)
		array[0].zoom = widt;
	else
		array[0].zoom = heigh;
	array[0].i = 0;
	array[0].j = 0;
}
