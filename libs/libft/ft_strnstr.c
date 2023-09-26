/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:59:56 by abashir           #+#    #+#             */
/*   Updated: 2023/07/16 17:31:06 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0 || haystack[0] == '\0')
		return (NULL);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (j < ft_strlen(needle) && haystack[i + j])
		{
			if (needle[j] != haystack[i + j])
				break ;
			else
				if ((j == ft_strlen(needle) - 1) && (i + j) < len)
					return ((char *)&haystack[i]);
			j++;
		}
		if ((i + j) > len)
			return (NULL);
		i++;
	}
	return (NULL);
}
