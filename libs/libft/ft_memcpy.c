/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:02:43 by ahans             #+#    #+#             */
/*   Updated: 2023/10/24 11:13:48 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	char		*dest;
	const char	*src;
	size_t		i;

	if (destination == NULL && source == NULL)
		return (NULL);
	dest = (char *)destination;
	src = (const char *)source;
	i = 0;
	while (size)
	{
		dest[i] = src[i];
		size--;
		i++;
	}
	return (destination);
}
