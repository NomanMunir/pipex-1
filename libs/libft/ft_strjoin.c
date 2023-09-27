/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:48:12 by abashir           #+#    #+#             */
/*   Updated: 2023/09/27 15:22:53 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, char const *s3)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	j = -1;
	if (s1 == NULL || s2 == NULL || s3 == NULL)
		return (NULL);
	new = (char *)ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) \
	+ ft_strlen(s3) + 1));
	if (new == NULL)
		return ((char *) NULL);
	while (s1[++i] != '\0')
		new[i] = s1[i];
	while (s2[++j] != '\0')
		new[i++] = s2[j];
	j = -1;
	while (s3[++j] != '\0')
		new[i++] = s3[j];
	new[i] = '\0';
	return (new);
}
