/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:46:03 by abashir           #+#    #+#             */
/*   Updated: 2023/09/24 18:03:01 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args_empty(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		error_exit(0, 0, 0);
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			error_exit(1, 0, 0);
		if (argv[i][j] == ' ')
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '\0')
				error_exit(1, 0, 0);
		}
		i++;
	}
}

