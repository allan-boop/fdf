/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <allan.hans68350@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:23:44 by ahans             #+#    #+#             */
/*   Updated: 2023/10/27 15:25:50 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searched_char)
{
	while (*string != '\0')
	{
		if (*string == (char)searched_char)
			return ((char *)string);
		string++;
	}
	if ((char)searched_char == '\0')
		return ((char *)string);
	return (NULL);
}
