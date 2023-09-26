/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:46:30 by abashir           #+#    #+#             */
/*   Updated: 2023/07/18 11:59:13 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d_ptr;
	const char	*s_ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	d_ptr = (char *)dst;
	s_ptr = (const char *)src;
	while (i < n)
	{
		d_ptr[i] = s_ptr[i];
		i++;
	}
	return (dst);
}
