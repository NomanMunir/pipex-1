/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:11:36 by alaa              #+#    #+#             */
/*   Updated: 2023/09/28 18:29:17 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "libs/libft/libft.h" 
# include "libs/get_next_line/get_next_line.h"
# include <errno.h>
typedef struct s_pipex
{
	char	*trim_argv;
	int		*pid;
	int		**fd;
	int		fd_in;
	int		ac;
	int		fd_out;
	char	**path;
	char	**cmds;
	char	***args;
	char	**envp;
	char	*infile;
	char	*outfile;
	char	*line;
	// int		fd[2];
	int		fdd;
}	t_pipex;

void	ft_init_pipe(t_pipex *pipex, char **argv, char **envp);
void	ft_free_pipex(t_pipex *pipex);
void	ft_free(char **tab);
void	error_exit(char *str, int flag, t_pipex *pipex);
void	check_error(int condition, char *str, int flag, t_pipex *pipex);
void	print_3d_array(t_pipex *pipex);
void    print_2d_array(char **tab);
int		ft_strcmp(const char *s1, const char *s2);
void    ft_free_3d(t_pipex *pipex);

#endif
