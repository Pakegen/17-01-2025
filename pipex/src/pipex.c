/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:07:57 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/17 11:13:31 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include "pipex.h"

void	pipex(t_pipex *data)
{
	int	in_fd;
	int	out_fd;
	int	fds[2];

	in_fd = open_file(data->infile, O_RDONLY, 0);
	if (in_fd == -1)
	{
		fds[0] = -1;
		cleanup(fds, 0, NULL);
		perror("bash");
	}
	out_fd = open_file(data->outfile, O_CREAT
			| O_WRONLY | O_TRUNC, 0644);
	if (out_fd == -1)
	{
		fds[0] = in_fd;
		fds[1] = -1;
		cleanup(fds, 1, NULL);
		perror("bash");
	}
	fds[0] = in_fd;
	fds[1] = out_fd;
	execute_pipeline(data, 0, in_fd);
	wait_for_all_children();
	cleanup(fds, 2, NULL);
}

void	execute_pipeline(t_pipex *data, int cmd_index, int input_fd)
{
	int		pipefd[2];
	int		output_fd;

	if (cmd_index == data->cmd_count - 1)
	{
		output_fd = open_file(data->outfile, O_CREAT
				| O_WRONLY | O_TRUNC, 0644);
		if (output_fd == -1)
			error_exit("ERROR: Unable to open output file\n");
		create_child(input_fd, output_fd, data->cmds[cmd_index], data->env);
		close(output_fd);
		return ;
	}
	if (pipe(pipefd) == -1)
		error_exit("ERROR: Failed to create pipe\n");
	create_child(input_fd, pipefd[1], data->cmds[cmd_index], data->env);
	if (pipefd[1] != -1)
		close(pipefd[1]);
	if (input_fd != -1)
		close(input_fd);
	execute_pipeline(data, cmd_index + 1, pipefd[0]);
}
