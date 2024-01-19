/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:23:44 by ahans             #+#    #+#             */
/*   Updated: 2024/01/19 16:00:25 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searched_char)
{
	if (!string)
		return (NULL);
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
