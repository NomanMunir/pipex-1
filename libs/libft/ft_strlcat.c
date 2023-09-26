/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:48:21 by abashir           #+#    #+#             */
/*   Updated: 2023/07/18 14:22:11 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	res;

	i = 0;
	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	d_len = ft_strlen(dst);
	res = ft_strlen(src) + ft_strlen(dst);
	if (d_len < dstsize)
	{
		while (src[i] != '\0' && (d_len + i + 1) < (dstsize))
		{
			dst[d_len + i] = src[i];
			i++;
		}
		dst[d_len + i] = '\0';
		return (res);
	}
	else
	{
		res = ft_strlen(src) + dstsize;
		return (res);
	}
}
