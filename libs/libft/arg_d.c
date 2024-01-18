/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:04:33 by ahans             #+#    #+#             */
/*   Updated: 2024/01/03 16:53:30 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags	arg_d(va_list arg, t_flags *ret)
{
	char	*str;

	str = ft_itoa(va_arg(arg, int));
	if (ft_putstr(str, ret) == -1)
		ret->len = -1;
	ret->charac++;
	free(str);
	return (*ret);
}
