/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:02:16 by ahans             #+#    #+#             */
/*   Updated: 2024/01/03 16:52:40 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_ptr(uintptr_t num, char min_maj)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16, min_maj);
		ft_put_ptr(num % 16, min_maj);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + min_maj), 1);
	}
}

t_flags	arg_p(unsigned long long ptr, t_flags *ret)
{
	if (write(1, "0x", 2) == -1)
	{
		ret->len = -1;
		return (*ret);
	}
	ret->len += 2;
	if (ptr == 0)
	{
		if (write(1, "0", 1) == -1)
		{
			ret->len = -1;
			return (*ret);
		}
		ret->len++;
	}
	else
	{
		ft_put_ptr(ptr, 'a');
		ret->len += ft_ptr_len(ptr);
	}
	ret->charac++;
	return (*ret);
}
