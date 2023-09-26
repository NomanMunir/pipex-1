/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:43:28 by abashir           #+#    #+#             */
/*   Updated: 2023/07/08 15:11:17 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int u)
{
	if (u >= 'A' && u <= 'Z')
		return (1);
	else
		return (0);
}

static int	ft_islower(int l)
{
	if (l >= 'a' && l <= 'z')
		return (1);
	else
		return (0);
}

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	else
		return (0);
}
