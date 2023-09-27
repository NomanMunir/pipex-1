/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:27:49 by abashir           #+#    #+#             */
/*   Updated: 2023/09/27 15:30:29 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read_file(t_list **lst, int fd)
{
	int		bytes;
	char	*buff;

	buff = malloc(sizeof(char) * ((long)BUFFER_SIZE + 1));
	if (buff == NULL)
		return ;
	bytes = 0;
	while (!ft_strchr_gnl(*lst))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buff[bytes] = '\0';
		ft_lstadd_back_gnl(lst, ft_strdup(buff));
		if (!lst)
			break ;
	}
	free(buff);
}

char	*ft_create_line(t_list *lst, size_t len)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	str = malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	while (lst != NULL)
	{
		i = 0;
		while (lst->content[i] && lst->content[i] != '\n')
			str[j++] = lst->content[i++];
		if (lst->content[i] == '\n')
			str[j] = '\n';
		lst = lst->next;
	}
	str[len + 1] = '\0';
	return (str);
}

void	ft_extra_line(t_list **lst, int *flag)
{
	char	*extra;
	size_t	len;
	char	*s;

	len = 0;
	extra = NULL;
	if (ft_strchr_gnl(*lst))
	{
		s = ft_strchr_gnl(*lst);
		while (s[len])
			len++;
	}
	if (len > 1)
		extra = ft_strdup(s + 1);
	ft_lstclear_gnl(lst);
	if (extra)
		ft_lstadd_back_gnl(lst, ft_strdup(extra));
	if ((extra == NULL && len > 1) || (!lst && extra))
		*flag = 1;
	free(extra);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*res;
	int				flag;

	flag = 0;
	res = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, res, 0))
	{
		ft_lstclear_gnl(&lst);
		return (NULL);
	}
	ft_read_file(&lst, fd);
	if (lst == NULL)
		return (NULL);
	res = ft_create_line(lst, ft_count_ch(lst));
	if (!res)
		return (NULL);
	ft_extra_line(&lst, &flag);
	if (flag == 1)
		return (NULL);
	return (res);
}
