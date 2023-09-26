/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:44:44 by abashir           #+#    #+#             */
/*   Updated: 2023/07/18 17:59:20 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*new;
	size_t		i;

	i = 0;
	if (size >= SIZE_MAX || size * count >= INT_MAX)
		return (NULL);
	if ((int)count < 0 || (int)size < 0)
		return (NULL);
	new = (char *)malloc(size * count);
	if (new == NULL)
		return (NULL);
	while (i < count * size)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}
