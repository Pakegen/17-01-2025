/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:08:21 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/17 09:53:00 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_child(int input_fd, int output_fd, char *cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit("ERROR FORK");
	if (pid == 0)
	{
		redirect(input_fd, output_fd);
		run_command(cmd, env);
	}
}

void	redirect(int input_fd, int output_fd)
{
	int	dup_in;
	int	dup_out;

	dup_in = dup2(input_fd, STDIN_FILENO);
	dup_out = dup2(output_fd, STDOUT_FILENO);
	if (dup_in == -1 || dup_out == -1)
		error_exit("ERROR: ECHEC IN THE REDIRECTION\n");
	close(input_fd);
	close(output_fd);
}

void	wait_for_all_children(void)
{
	int		status;
	pid_t	pid;

	pid = wait(&status);
	while (pid > 0)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			ft_putstr_fd("WARNING PROCESS FAILED\n", 2);
			ft_putnbr_fd(WEXITSTATUS(status), 2);
			ft_putendl_fd("", 2);
		}
		else if (WIFSIGNALED(status))
		{
			ft_putstr_fd("WARNING COMAND TERMINATED\n", 2);
			ft_putnbr_fd(WTERMSIG(status), 2);
			ft_putendl_fd("", 2);
		}
		pid = wait(&status);
	}
}

void	run_command(char *cmd, char **env)
{
	char	**args;
	char	*resolved_cmd;

	if (!cmd || cmd[0] == '\0')
		error_exit("ERROR: Invalid command\n");
	args = ft_split(cmd, ' ');
	if (!args || !args[0])
		error_exit("ERROR: Failed to parse command\n");
	resolved_cmd = find_command_path(args[0], env);
	if (!resolved_cmd)
	{
		ft_putstr_fd("ERROR: Command not found: ", 2);
		ft_putendl_fd(args[0], 2);
		free_split(args);
		exit(127);
	}
	execve(resolved_cmd, args, env);
	ft_putstr_fd("ERROR, FAILED TO EXECUTE COMMAND", 2);
	ft_putendl_fd(cmd, 2);
	free(resolved_cmd);
	free_split(args);
	exit(127);
}
