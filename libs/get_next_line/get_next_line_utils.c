/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:23:45 by abashir           #+#    #+#             */
/*   Updated: 2023/09/15 19:42:01 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(t_list *lst)
{
	int	i;

	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		i = 0;
		while (lst->content[i] && i < BUFFER_SIZE)
		{
			if (lst->content[i] == '\n')
				return ((char *)&lst->content[i]);
			++i;
		}
		lst = lst->next;
	}
	return (NULL);
}

void	ft_lstadd_back_gnl(t_list **lst, char *content)
{
	t_list	*new;
	t_list	*tmp;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->content = content;
	new->next = NULL;
	if (new == NULL)
		return ;
	tmp = NULL;
	if (*lst == NULL)
		*lst = new;
	else if (*lst)
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

char	*ft_strdup(const char *s1)
{
	char		*new;
	int			i;

	i = 0;
	while (s1[i])
		i++;
	new = (char *)(malloc(sizeof(char) * (i + 1)));
	i = 0;
	if (new == NULL)
		return ((char *) NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	ft_lstclear_gnl(t_list **lst)
{
	t_list	*temp;

	temp = NULL;
	if (lst)
	{
		temp = *lst;
		while (temp != NULL)
		{
			temp = temp->next;
			free((*lst)->content);
			free(*lst);
			*lst = temp;
		}
		*lst = NULL;
	}
}

size_t	ft_count_ch(t_list *ptr)
{
	int		i;
	int		len;
	char	*res;

	len = 0;
	res = NULL;
	while (ptr != NULL)
	{
		i = 0;
		res = ptr->content;
		while (res[i] && res[i] != '\n')
			i++;
		len += i;
		ptr = ptr->next;
	}
	if (res[i] == '\0')
		len--;
	return (len);
}
