/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:10:47 by abashir           #+#    #+#             */
/*   Updated: 2023/09/19 13:34:39 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*current;

	current = *lst;
	if (lst)
	{
		temp = current->next;
		while (current)
		{
			temp = current->next;
			free(current);
			current = temp;
		}
		*lst = NULL;
	}
}

void	error_exit(int error, int flag, char **array)
{
	if (error == 1)
		ft_putstr_fd("Error\n", 2);
	if (flag == 1)
		ft_free_array(array);
	exit(0);
}

void	error_free(int error, t_stack **stack_a)
{
	ft_lstclear(stack_a);
	error_exit(error, 0, 0);
}
