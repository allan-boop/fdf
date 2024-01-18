/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:01:03 by ahans             #+#    #+#             */
/*   Updated: 2024/01/03 16:51:58 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str, t_flags *ret)
{
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		ret->len += 6;
		return (0);
	}
	while (*str)
	{
		if (write(1, str, 1) == -1)
			return (-1);
		str++;
		ret->len++;
	}
	return (0);
}
