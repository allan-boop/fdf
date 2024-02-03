/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:43:25 by ahans             #+#    #+#             */
/*   Updated: 2024/02/03 18:46:40 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(char *nb)
{
	int		i;
	int		j;
	int		nb_base;
	char	*base;

	if (!nb)
		return (0);
	i = 0;
	j = 0;
	nb_base = 0;
	base = "0123456789abcdef";
	while (nb[i])
	{
		while (base[j] && base[j] != nb[i])
			j++;
		if (base[j] == nb[i])
			nb_base = nb_base * 16 + j;
		i++;
		j = 0;
	}
	return (nb_base);
}
