/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:32:53 by ahans             #+#    #+#             */
/*   Updated: 2024/02/05 14:07:37 by ahans            ###   ########.fr       */
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
