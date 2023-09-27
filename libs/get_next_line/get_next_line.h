/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:50:01 by abashir           #+#    #+#             */
/*   Updated: 2023/09/27 15:26:59 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back_gnl(t_list **lst, char *content);
char	*ft_strchr_gnl(t_list *list);
char	*ft_strdup(const char *s1);
void	ft_read_file(t_list **lst, int fd);
char	*ft_create_line(t_list *lst, size_t len);
void	ft_extra_line(t_list **lst, int *flag);
char	*get_next_line(int fd);
void	ft_lstclear_gnl(t_list **lst);
size_t	ft_count_ch(t_list *ptr);

#endif
