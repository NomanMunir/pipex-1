/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:00:17 by abashir           #+#    #+#             */
/*   Updated: 2023/09/28 09:59:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args_empty(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	check_error(argc < 4, "Error: Wrong number of arguments\n", 0, NULL);
	while (i < argc)
	{
		j = 0;
		check_error(argv[i][0] == '\0', "Error: Empty argument\n", 0, NULL);
		if (argv[i][j] == ' ')
		{
			while (argv[i][j] == ' ')
				j++;
			check_error(argv[i][j] == '\0', "Error: Empty argument\n", 0, NULL);
		}
		i++;
	}
}

void	ft_open_files(t_pipex *pipex, char **argv)
{
	if (ft_strncmp(pipex->trim_argv, "here_doc", 8) == 0)
	{
		pipex->fd_in = open("here_doc", O_RDONLY);
		pipex->fd_out = open(argv[pipex->ac], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	else if (ft_strncmp(argv[1], "/dev/stdin", ft_strlen(argv[1])) == 0)
	{
    	pipex->fd_in = dup2(0, STDIN_FILENO);
		pipex->fd_out = open(argv[pipex->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	else
	{
		pipex->fd_in = open(argv[1], O_RDONLY);
		pipex->fd_out = open(argv[pipex->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	check_error(pipex->fd_in == -1, "Open file error", 0, pipex);
	check_error(pipex->fd_out == -1, "Create file error", 1, pipex);
}

void	ft_exec(t_pipex *pipex, int i, char *cmd, char **envp)
{
	int		fd[2];
	int		pid;

	if (pipe(fd) == -1)
		return (perror("pipe"), ft_free_pipex(pipex));
	pid = fork();
	if (pid == -1)
		return (perror("fork:"), ft_free_pipex(pipex));
	if (pid == 0)
	{
		if (i == 0)
			dup2(pipex->fd_in, STDIN_FILENO);
		dup2(pipex->fdd, STDIN_FILENO);
		if (pipex->cmds[i + 1] != NULL)
			dup2(fd[1], STDOUT_FILENO);
		else if (pipex->cmds[i + 1] == NULL)
			dup2(pipex->fd_out, STDOUT_FILENO);
		close(fd[0]);
		if (execve(cmd, pipex->args[i], envp) == -1)
		{
			perror("command not found");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		close(fd[1]);
		pipex->fdd = fd[0];
	}
}

void	read_here_doc(t_pipex *pipex, char **argv, int fd)
{
	ft_putstr_fd("pipe heredoc> ", 1);
	pipex->line = get_next_line(0);
	check_error(pipex->line == NULL, "Empty here_doc", 1, pipex);
	while (ft_strcmp(argv[2], pipex->line) && pipex->line)
	{
		ft_putstr_fd(pipex->line, fd);
		free(pipex->line);
		ft_putstr_fd("pipe heredoc> ", 1);
		pipex->line = get_next_line(0);
		check_error(pipex->line == NULL, "here_doc exit", 1, pipex);
	}
	free(pipex->line);
}

void	init_here_doc(t_pipex *pipex, char **argv, int ac, char **envp)
{
	int		fd;

	pipex->trim_argv = ft_strtrim(argv[1], " ");
	if (ft_strncmp(pipex->trim_argv, "here_doc", 8) == 0)
	{
		pipex->fd_in = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		check_error(pipex->fd_in == -1, "Create file error", 0, pipex);
		read_here_doc(pipex, argv, pipex->fd_in);
		close(pipex->fd_in);
		pipex->ac = ac - 1;
	}
	else
		pipex->ac = ac;
}

void	ft_pipeline(t_pipex *pipex, char **envp)
{
	int	i;

	i = -1;
	while (pipex->cmds[++i])
		ft_exec(pipex, i, pipex->cmds[i], envp);
}

int	main(int ac, char **ag, char **envp)
{
	t_pipex	*pipex;

	check_args_empty(ac, ag);
	pipex = (t_pipex *)ft_calloc(1, sizeof(t_pipex));
	check_error(!pipex, "malloc", 0, NULL);
	init_here_doc(pipex, ag, ac, envp);
	ft_open_files(pipex, ag);
	ft_init_pipe(pipex, ag, envp);
	ft_pipeline(pipex, envp);
	ft_free_pipex(pipex);
}


