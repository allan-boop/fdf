/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:00:47 by ahans             #+#    #+#             */
/*   Updated: 2024/01/19 16:02:11 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!source)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(source) + 1);
	if (!new)
		return (NULL);
	while (*source)
		new[i++] = *source++;
	new[i] = '\0';
	return (new);
}
