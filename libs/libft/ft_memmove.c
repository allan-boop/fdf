/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:02:48 by ahans             #+#    #+#             */
/*   Updated: 2023/10/19 18:18:42 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	char		*dest;
	const char	*src;
	size_t		i;

	dest = (char *)destination;
	src = (char *)source;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		while (i < size)
		{
			dest[size - 1 - i] = src[size - 1 - i];
			i++;
		}
	}
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}
