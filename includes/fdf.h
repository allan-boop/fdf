/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:54:03 by ahans             #+#    #+#             */
/*   Updated: 2024/01/25 15:49:25 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include "MLX42.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_var_stock
{
	int32_t				x;
	int32_t				y;
	int32_t				z;
	int32_t				r;
	int32_t				g;
	int32_t				b;
	int32_t				a;
	int32_t				line_size;
	int32_t				line_count;
}	t_var_stock;

void	draw_line(t_var_stock map, t_var_stock map2, void *img, int32_t ratio);

#endif
