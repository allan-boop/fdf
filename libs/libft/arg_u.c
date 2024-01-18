/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:12:26 by ahans             #+#    #+#             */
/*   Updated: 2024/01/03 16:53:47 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

t_flags	arg_u(unsigned int n, t_flags *ret)
{
	char	*num;

	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
		{
			ret->len = -1;
			return (*ret);
		}
		ret->len++;
		ret->charac++;
	}
	else
	{
		num = ft_uitoa(n);
		if (ft_putstr(num, ret) == -1)
			ret->len = -1;
		free(num);
		ret->charac++;
	}
	return (*ret);
}
