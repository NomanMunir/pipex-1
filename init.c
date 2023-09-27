/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:06 by abashir           #+#    #+#             */
/*   Updated: 2023/09/27 15:20:26 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_find_path(t_pipex *pipex, char **envp)
{
	int		i;
	char	*tmp;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			check_error(!tmp, "malloc", 1, pipex);
			pipex->path = ft_split(tmp, ':');
			free(tmp);
			check_error(!pipex->path, "malloc", 1, pipex);
			return ;
		}
	}
}

void	ft_set_path(t_pipex *pipex)
{
	int		i;
	int		j;
	char	*temp;

	j = -1;
	pipex->cmds = ft_calloc((pipex->ac - 2), sizeof(char *));
	check_error(!pipex->cmds, "malloc", 1, pipex);
	
	while (pipex->args[++j])
	{
		i = -1;
		while (pipex->path[++i])
		{
			if (pipex->args[j][0][0] == '/' && access(pipex->args[j][0], F_OK) == 0 \
			&& access(pipex->args[j][0], X_OK) == 0)
			{
				pipex->cmds[j] = ft_strdup(pipex->args[j][0]);
				check_error(!pipex->cmds[j], "malloc", 1, pipex);
				break ;
			}
			temp = ft_strjoin(pipex->path[i], "/", pipex->args[j][0]);
			check_error(!temp, "malloc", 1, pipex);
			if (access(temp, F_OK) == 0 && access(temp, X_OK) == 0)
			{
				pipex->cmds[j] = ft_strdup(temp);
				free(temp);
				check_error(!pipex->cmds[j], "malloc", 1, pipex);
				break ;
			}
			free(temp);
		}
		check_error(!pipex->cmds[j], "Command not found!", 1, pipex);
	}
	pipex->cmds[j] = NULL;
}

static void ft_create_args(t_pipex *pipex, char **arg)
{
	int	i;
	int	j;
	 
	j = 0;
	i = 2;
	pipex->args = ft_calloc((pipex->ac - 2), sizeof(char **));
	check_error(!pipex->args, "malloc", 1, pipex);
	while (arg[i + 1])
	{
		pipex->args[j] = ft_split(arg[i], ' ');
		check_error(!pipex->args[j], "malloc", 1, pipex);
		i++;
		j++;
	}
	pipex->args[j] = NULL;
}

void	ft_init_pipe(t_pipex *pipex, char **argv, char **envp)
{
	if (ft_strncmp(pipex->trim_argv, "here_doc", 8) == 0)
		argv++;
	pipex->envp = envp;
	pipex->infile = argv[1];
	pipex->outfile = argv[pipex->ac - 1];
	ft_create_args(pipex, argv);
	ft_find_path(pipex, envp);
	ft_set_path(pipex);
}
