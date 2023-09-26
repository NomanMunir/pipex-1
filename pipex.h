/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:11:36 by alaa              #+#    #+#             */
/*   Updated: 2023/09/26 15:40:26 by abashir          ###   ########.fr       */
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

typedef struct s_pipex
{
	int		fd_in;
	int		ac;
	int		fd_out;
	char	**path;
	char	**cmds;
	char	***args;
	char	**envp;
	char	*infile;
	char	*outfile;
	int		fd[2];
}	t_pipex;

void	ft_init_pipe(t_pipex *pipex, char **argv, char **envp);
void	ft_free_pipex(t_pipex *pipex);
void	ft_free(char **tab);
void	error_exit(char *str);
void	print_3d_array(t_pipex *pipex);
void    print_2d_array(char **tab);

#endif
