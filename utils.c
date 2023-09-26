/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:22:34 by abashir           #+#    #+#             */
/*   Updated: 2023/09/25 16:36:30 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_free(char **tab)
{
    int i;

    i = -1;
    while (tab[++i])
        free(tab[i]);
    free(tab);
}

void ft_free_pipex(t_pipex *pipex)
{
    // ft_free(pipex->cmd1);
    // ft_free(pipex->cmd2);
    ft_free(pipex->path);
    // free(pipex->r_path_cmd1);
    // free(pipex->r_path_cmd2);
    free(pipex);
    exit(1);
}

// void	print_struct(t_pipex *pipex)
// {
// 	int	i;

// 	i = -1;
// 	printf("infile: %s\n", pipex->infile);
// 	printf("outfile: %s\n", pipex->outfile);
// 	printf("cmd1: ");
// 	while (pipex->cmd1[++i])
// 		printf("%s ", pipex->cmd1[i]);
// 	printf("\ncmd2: ");
// 	i = -1;
// 	while (pipex->cmd2[++i])
// 		printf("%s ", pipex->cmd2[i]);
// 	printf("\n");
// 	i = -1;
// 	printf("path: ");
// 	while (pipex->path[++i])
// 		printf("%s ", pipex->path[i]);
// 	printf("\n");
// 	printf("r_path: %s\n", pipex->r_path_cmd1);
// 	printf("r_path: %s\n", pipex->r_path_cmd2);
// 	printf("fd_in: %d\n", pipex->fd_in);
// 	printf("fd_out: %d\n", pipex->fd_out);
// }

void print_3d_array(t_pipex *pipex)
{
    int	i;
    int	j;

    i = -1;
    while (pipex->args[++i])
    {
        j = -1;
        while (pipex->args[i][++j])
            printf("%s ", pipex->args[i][j]);
        printf("\n");
    }
}

void    print_2d_array(char **tab)
{
    int i;

    i = -1;
    while (tab[++i])
        printf("%s\n", tab[i]);
}

