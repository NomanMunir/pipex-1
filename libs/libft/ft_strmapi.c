/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:48:55 by abashir           #+#    #+#             */
/*   Updated: 2023/07/18 18:53:26 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	i = 0;
	if (s == NULL || !f)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (new == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new[i] = (f)(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
