/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:49:31 by abashir           #+#    #+#             */
/*   Updated: 2023/07/16 18:05:54 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	new = (char *)(malloc(sizeof(char) * (len + 1)));
	if (new == NULL)
		return (NULL);
	while (s[i] != '\0' && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
