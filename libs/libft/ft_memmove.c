/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:46:44 by abashir           #+#    #+#             */
/*   Updated: 2023/07/13 12:55:57 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d_ptr;
	const char	*s_ptr;

	if (!dst && !src)
		return (NULL);
	i = 0;
	d_ptr = (char *)dst;
	s_ptr = (char *)src;
	if (src < dst && (dst < src + len))
	{
		while (len-- > 0)
		{
			d_ptr[len] = s_ptr[len];
		}
	}
	else
	{
		while (i < len)
		{
			d_ptr[i] = s_ptr[i];
			i++;
		}
	}
	return (dst);
}
