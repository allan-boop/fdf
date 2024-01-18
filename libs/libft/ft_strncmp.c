/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:46:58 by ahans             #+#    #+#             */
/*   Updated: 2023/10/20 11:12:36 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length && *first != '\0' && *second != '\0')
	{
		if ((unsigned char)*first != (unsigned char)*second)
			return ((unsigned char)*first - (unsigned char)*second);
		second++;
		first++;
		i++;
	}
	if (i == length)
		return (0);
	return ((unsigned char)*first - (unsigned char)*second);
}
