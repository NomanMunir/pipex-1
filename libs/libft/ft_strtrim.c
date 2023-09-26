/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:49:25 by abashir           #+#    #+#             */
/*   Updated: 2023/07/13 18:51:14 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *new, const char *s1, int start, int end)
{
	int	j;

	j = 0;
	end = ft_strlen(s1) - end;
	while (s1[start] && start < end)
	{
		new[j] = s1[start];
		start++;
		j++;
	}
	new[j] = '\0';
}

static int	ft_find(char const s1, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (set[j] == s1)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	e;
	size_t	len_s;
	char	*new;

	if (s1 == NULL)
		return (NULL);
	s = 0;
	e = 0;
	len_s = ft_strlen(s1);
	while (s1[s] && ft_find(s1[s], set))
		s++;
	while (s1[len_s - 1 - e] && ft_find(s1[len_s - 1 - e], set))
		e++;
	if (e == len_s || s == len_s)
		new = (char *)malloc(sizeof(char) * 1);
	else
		new = (char *)malloc(sizeof(char) *(len_s - s - e + 1));
	if (new)
	{
		ft_strcpy(new, s1, s, e);
		return (new);
	}
	return (NULL);
}
