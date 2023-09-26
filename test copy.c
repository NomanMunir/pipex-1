/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:00:17 by abashir           #+#    #+#             */
/*   Updated: 2023/09/26 13:54:58 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args_empty(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc <= 4)
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
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in == -1)
		return (perror("Create file error"), free(pipex), exit(1));
	pipex->fd_out = open(argv[pipex->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (pipex->fd_out == -1)
	{
		close(pipex->fd_in);
		return (perror("Create file error"), free(pipex), exit(1));
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

int	main(int ac, char **ag, char **envp)
{
	t_pipex	*pipex;
	int		i;

	i = 0;
	check_args_empty(ac, ag);
	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (perror("malloc: "), 1);
	pipex->ac = ac;
	ft_open_files(pipex, ag);
	ft_init_pipe(pipex, ag, envp, ac);
	while (pipex->cmds[i])
	{
		ft_exec(pipex, i, pipex->cmds[i], envp);
		i++;
	}

	// int pid1;
	// int pid2;
	// int fd[2];
	// if (pipe(fd) == -1)
	// 	return (perror("pipe"), ft_free_pipex(pipex), 1);
	// pid1 = fork();
	// if (pid1 == -1)
	// 	return (perror("fork:"), ft_free_pipex(pipex), 1);
	// if (pid1 == 0)
	// {
	// 	dup2(pipex->fd_in, STDIN_FILENO);
	// 	dup2(fd[1], STDOUT_FILENO);
	// 	close(fd[0]);
	// 	close(fd[1]);
	// 	close(pipex->fd_in);
	// 	if (execve(pipex->cmds[0], pipex->args[0], envp) == -1)
	// 		return (perror("Command not found: "), ft_free_pipex(pipex), 1);
	// }
	// else
	// 	wait(NULL);
	// pid2 = fork();
	// if (pid2 == -1)
	// {
	// 	perror("Error: ");
	// 	return (0);
	// }
	// if (pid2 == 0)
	// {
	// 	dup2(pipex->fd_out, STDOUT_FILENO);
	// 	dup2(fd[0], STDIN_FILENO);
	// 	close(fd[0]);
	// 	close(fd[1]);
	// 	close(pipex->fd_out);
	// 	if (execve(pipex->cmds[1], pipex->args[1], envp) == -1)
	// 		return (perror("Command not found: "), ft_free_pipex(pipex), 1);
	// }
	// else
	// 	wait(NULL);
	// close(fd[0]);
	// close(fd[1]);
	// return (ft_free_pipex(pipex), exit(0),  0);
}


	// int		fd[2];
	// int		pid;

	// if (pipe(fd) == -1)
	// 	return (perror("pipe"), ft_free_pipex(pipex));
	// pid = fork();
	// if (pid == -1)
	// 	return (perror("fork:"), ft_free_pipex(pipex));
	// if (pid == 0)
	// {
	// 	if (i == 0)
	// 	{
	// 		printf("fd_in: %d\n", pipex->fd_in);
	// 		dup2(pipex->fd_in, STDIN_FILENO);
	// 		dup2(fd[1], STDOUT_FILENO);
	// 	}
	// 	else if (pipex->cmds[i + 1] == NULL)
	// 	{
	// 		printf("fd_out: %d\n", pipex->fd_out);
	// 		dup2(fd[0], STDIN_FILENO);
	// 		dup2(pipex->fd_out, STDOUT_FILENO);
	// 	}
	// 	else
	// 	{
	// 		printf("fd[0]: %d\n", fd[0]);
	// 		dup2(fd[0], STDIN_FILENO);
	// 		dup2(fd[1], STDOUT_FILENO);
	// 	}
	// 	close(fd[0]);
	// 	close(fd[1]);
	// 	if (execve(cmd, pipex->args[i], envp) == -1)
	// 		return (perror("Command not found: "), ft_free_pipex(pipex));
	// }
	// else
	// {
	// 	wait(NULL);
	// 	close(fd[0]);
	// 	close(fd[1]);
	// }

// 	void	ft_exec(t_pipex *pipex, int i, char *cmd, char **envp)
// {
// 	int		fd[2];
// 	int		pid;
// 	int		fdd;

// 	if (pipe(fd) == -1)
// 		return (perror("pipe"), ft_free_pipex(pipex));
// 	pid = fork();
// 	if (pid == -1)
// 		return (perror("fork:"), ft_free_pipex(pipex));
// 	if (pid == 0)
// 	{
// 		dup2(fdd, STDIN_FILENO);
// 		if (pipex->cmds[i + 1] != NULL)
// 			dup2(fd[1], STDOUT_FILENO);
// 		close(fd[0]);
// 		// if (i == 0)
// 		// {
// 		// 	printf("fd_in: %d\n", pipex->fd_in);
// 		// 	dup2(pipex->fd_in, STDIN_FILENO);
// 		// 	dup2(fd[1], STDOUT_FILENO);

// 		// }
// 		// else if (pipex->cmds[i + 1] == NULL)
// 		// {
// 		// 	printf("fd_out: %d\n", pipex->fd_out);
// 		// 	dup2(fd[0], STDIN_FILENO);
// 		// 	dup2(pipex->fd_out, STDOUT_FILENO);
// 		// }
// 		// else
// 		// {
// 		// 	printf("fd[0]: %d\n", fd[0]);
// 		// 	dup2(fd[0], STDIN_FILENO);
// 		// 	dup2(fd[1], STDOUT_FILENO);

// 		// }
// 		// close(fd[0]);
// 		// close(fd[1]);
// 		if (execve(cmd, pipex->args[i], envp) == -1)
// 			return (perror("Command not found: "), ft_free_pipex(pipex));
// 	}
// 	else
// 	{
// 		wait(NULL);
// 		close(fd[1]);
// 		fdd = fd[0];
// 	}
// }