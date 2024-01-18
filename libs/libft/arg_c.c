/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:59:58 by ahans             #+#    #+#             */
/*   Updated: 2024/01/03 16:52:30 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags	arg_c(va_list arg, t_flags *ret)
{
	char	f;

	f = va_arg(arg, int);
	if (write(1, &f, 1) == -1)
	{
		ret->len = -1;
		return (*ret);
	}
	ret->charac++;
	ret->len++;
	return (*ret);
}
