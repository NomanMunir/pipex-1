/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:00:17 by abashir           #+#    #+#             */
/*   Updated: 2023/09/26 14:53:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args_empty(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 4)
		error_exit("Error: wrong number of arguments\n");
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			error_exit("Error: empty argument\n");
		if (argv[i][j] == ' ')
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '\0')
				error_exit("Error: empty argument\n");
		}
		i++;
	}
}

void	ft_open_files(t_pipex *pipex, char **argv)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		pipex->fd_in = open("in", O_RDONLY);
		pipex->fd_out = open(argv[pipex->ac], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	else
	{
		pipex->fd_in = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		pipex->fd_out = open(argv[pipex->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	if (pipex->fd_in == -1)
		return (perror("Create file error1"), free(pipex), exit(1));

	if (pipex->fd_out == -1)
	{
		close(pipex->fd_in);
		return (perror("Create file error2"), free(pipex), exit(1));
	}
}

void	ft_exec(t_pipex *pipex, int i, char *cmd, char **envp)
{
	int		fd[2];
	int		pid;
	int		fdd;

	if (pipe(fd) == -1)
		return (perror("pipe"), ft_free_pipex(pipex));
	pid = fork();
	if (pid == -1)
		return (perror("fork:"), ft_free_pipex(pipex));
	if (pid == 0)
	{
		if (i == 0)
			dup2(pipex->fd_in, STDIN_FILENO);
		dup2(fdd, STDIN_FILENO);
		if (pipex->cmds[i + 1] != NULL)
			dup2(fd[1], STDOUT_FILENO);
		else if (pipex->cmds[i + 1] == NULL)
			dup2(pipex->fd_out, STDOUT_FILENO);
		close(fd[0]);
		if (execve(cmd, pipex->args[i], envp) == -1)
			return (perror("Command not found: "), ft_free_pipex(pipex));
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		fdd = fd[0];
	}
}

void	init_here_doc(t_pipex *pipex, char **argv, char **envp)
{
	int		fd;
	char	*line;

	fd = open("in", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	ft_putstr_fd("pipe heredoc> ", 1);
	line = get_next_line(0);
	while (ft_strncmp(argv[2], line, ft_strlen(argv[2]) != 0) && line)
	{
		ft_putstr_fd(line, fd);
		free(line);
		ft_putstr_fd("pipe heredoc> ", 1);
		line = get_next_line(0);
	}
	free(line);
	close(fd);
}

int	main(int ac, char **ag, char **envp)
{
	t_pipex	*pipex;
	int		i;

	i = 0;
	check_args_empty(ac, ag);
	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (perror("malloc"), 1);
	pipex->ac = ac;
	if (ft_strncmp(ag[1], "here_doc", 8) == 0)
	{
		init_here_doc(pipex, ag, envp);
		pipex->ac = ac - 1;
	}
	ft_open_files(pipex, ag);
	ft_init_pipe(pipex, ag, envp);
	while (pipex->cmds[i])
	{
		ft_exec(pipex, i, pipex->cmds[i], envp);
		i++;
	}
	close(pipex->fd_in);
	close(pipex->fd_out);
	unlink(pipex->infile);
	ft_free_pipex(pipex);
}
