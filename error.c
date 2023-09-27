/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:28:55 by abashir           #+#    #+#             */
/*   Updated: 2023/09/27 17:39:26 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *str, int flag, t_pipex *pipex)
{
	if (pipex)
	{
		if (pipex->trim_argv)
			free(pipex->trim_argv);
		if (pipex->args)
			ft_free_3d(pipex);
		if (pipex->path)
			ft_free(pipex->path);
		if (pipex->cmds)
			ft_free(pipex->cmds);
		if (flag == 1)
		{
			close(pipex->fd_in);
			close(pipex->fd_out);
			if (pipex->outfile)
				unlink(pipex->outfile);
			unlink("here_doc");
		}
		if (pipex)
			free(pipex);
	}
	perror(str);
	exit(1);
}

void	check_error(int condition, char *str, int flag, t_pipex *pipex)
{
	if (condition && pipex)
		error_exit(str, flag, pipex);
	else if (condition && !pipex)
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		exit(1);
	}
}

void ft_free(char **tab)
{
    int i;

    i = -1;
    while (tab[++i])
        free(tab[i]);
    free(tab);
}

void    ft_free_3d(t_pipex *pipex)
{
    int i;
    int j;

    i = -1;
    while (pipex->args[++i])
    {
        j = -1;
        while (pipex->args[i][++j])
            free(pipex->args[i][j]);
        free(pipex->args[i]);
    }
    free(pipex->args);
}
void ft_free_pipex(t_pipex *pipex)
{
	free(pipex->trim_argv);
	ft_free_3d(pipex);
	ft_free(pipex->path);
	ft_free(pipex->cmds);
	close(pipex->fd_in);
	close(pipex->fd_out);
	unlink("here_doc");
    free(pipex);
    exit(1);
}