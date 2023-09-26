/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:06 by abashir           #+#    #+#             */
/*   Updated: 2023/09/26 15:13:44 by codespace        ###   ########.fr       */
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
			// if (!tmp)
			// 	return (ft_free(pipex->cmd1), \
			// 	ft_free(pipex->cmd2), free(pipex), exit(1));
			pipex->path = ft_split(tmp, ':');
			free(tmp);
			// if (!pipex->path)
			// 	return (ft_free(pipex->cmd1), \
			// 	ft_free(pipex->cmd2), free(pipex), exit(1));
			return ;
		}
	}
}

void	ft_set_path(t_pipex *pipex)
{
	int		i;
	int		j;
	char	*temp;
	char	*temp2;

	j = -1;
	pipex->cmds = malloc(sizeof(char *) * (pipex->ac - 2));
	while (pipex->args[++j])
	{
		i = -1;
		while (pipex->path[++i])
		{
			if (pipex->args[j][0][0] == '/' && access(pipex->args[j][0], F_OK) == 0 \
			&& access(pipex->args[j][0], X_OK) == 0)
			{
				pipex->cmds[j] = ft_strdup(pipex->args[j][0]);
				break ;
			}
			temp = ft_strjoin(pipex->path[i], "/");
			temp2 = ft_strjoin(temp, pipex->args[j][0]);
			free(temp);
			if (access(temp2, F_OK) == 0 && access(temp2, X_OK) == 0)
			{
				pipex->cmds[j] = ft_strdup(temp2);
				free(temp2);
				break ;
			}
			free(temp2);
		}
		if (!pipex->cmds[j])
			return (ft_putstr_fd("Error: command not found\n", 2));
	}
	pipex->cmds[j] = NULL;
}


static void ft_create_args(t_pipex *pipex, char **arg)
{
	int	i;
	int	j;
	 
	j = 0;
	i = 2;
	pipex->args = malloc(sizeof(char **) * (pipex->ac - 2));
	if (!pipex->args)
		return (free(pipex), exit(1));
	while (arg[i + 1])
	{
		pipex->args[j] = ft_split(arg[i], ' ');
		if (!pipex->args[j])
			return (free(pipex), exit(1));
		i++;
		j++;
	}
	pipex->args[j] = NULL;
}

void	ft_init_pipe(t_pipex *pipex, char **argv, char **envp)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		argv++;
	pipex->envp = envp;
	pipex->infile = argv[1];
	pipex->outfile = argv[pipex->ac - 1];
	ft_create_args(pipex, argv);
	// print_3d_array(pipex);
	ft_find_path(pipex, envp);
	ft_set_path(pipex);
	// print_2d_array(pipex->cmds);
	// return (ft_putstr_fd("Error: arguments are not valid\n", 2), exit(1));
}
