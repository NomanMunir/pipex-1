/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:46:07 by abashir           #+#    #+#             */
/*   Updated: 2023/07/18 18:51:06 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_len(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*new;
	long	nbr;

	nbr = n;
	i = ft_nbr_len(nbr);
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	new[i] = '\0';
	if (nbr < 0)
	{
		new[0] = '-';
		nbr = nbr * -1;
	}
	if (nbr == 0)
		new[0] = nbr + '0';
	while (nbr > 0)
	{
		new[i - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	return (new);
}
