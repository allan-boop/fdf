/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:19:13 by ahans             #+#    #+#             */
/*   Updated: 2023/10/30 12:05:28 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		target;
	size_t				i;

	i = 0;
	src = s;
	target = (unsigned char)c;
	while (i < n)
	{
		if (src[i] == target)
		{
			return ((void *)&src[i]);
		}
		i++;
	}
	return (NULL);
}
