/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:29:23 by ahans             #+#    #+#             */
/*   Updated: 2024/02/03 23:26:04 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clear(mlx_image_t *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		img = img;
		mlx_put_pixel(img, x, y, 0x0);
		x++;
		if (x == WIDTH)
		{
			x = 0;
			y++;
		}
	}
}

void	rotation_handler(t_hook_pos *data)
{
	clear(data->img);
	rotation_x(data->vars, (&data->vars[0])->line_count \
			* (&data->vars[0])->line_size, data->angle_x);
	rotation_y(data->vars, (&data->vars[0])->line_count \
			* (&data->vars[0])->line_size, data->angle_y);
	rotation_z(data->vars, (&data->vars[0])->line_count \
			* (&data->vars[0])->line_size, data->angle_z);
	recalcul_center(data->vars);
	draw_map(data->vars, data->img);
}

void	inc_angle(t_hook_pos *data, int flag)
{
	if (flag == 1)
		data->angle_x += 6;
	if (flag == 2)
		data->angle_x -= 6;
	if (flag == 3)
		data->angle_y += 6;
	if (flag == 4)
		data->angle_y -= 6;
	if (flag == 5)
		data->angle_z += 6;
	if (flag == 6)
		data->angle_z -= 6;
	rotation_handler(data);
}

void	ft_rotate(t_hook_pos *hook, mlx_t *mlx)
{
	hook = hook;
	hook->angle_x = 0;
	hook->angle_y = 0;
	hook->angle_z = 0;
	if (mlx_is_key_down(hook->mlx, MLX_KEY_D))
		inc_angle(hook, 1);
	else if (mlx_is_key_down(hook->mlx, MLX_KEY_A))
		inc_angle(hook, 2);
	else if (mlx_is_key_down(hook->mlx, MLX_KEY_W))
		inc_angle(hook, 3);
	else if (mlx_is_key_down(hook->mlx, MLX_KEY_S))
		inc_angle(hook, 4);
	else if (mlx_is_key_down(hook->mlx, MLX_KEY_Q))
		inc_angle(hook, 5);
	else if (mlx_is_key_down(hook->mlx, MLX_KEY_E))
		inc_angle(hook, 6);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	rotation_handler(hook);
}


void	ft_hook(void *param)
{
	mlx_t		*mlx;
	t_hook_pos	*hook;

	hook = param;
	mlx = hook->mlx;

	ft_rotate(hook, mlx);
}
