/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:04:10 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 22:45:20 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include "pipex.h"

int	open_file(char *filename, int flags, int mode)
{
	int	fd;

	fd = open(filename, flags, mode);
	if (fd == -1)
	{
		if (access(filename, F_OK) == -1)
			ft_putstr_fd("ERROR: File does not exist: ", 2);
		else if (access(filename, R_OK) == -1 && (flags & O_RDONLY))
			ft_putstr_fd("ERROR: No read permission for file: ", 2);
		else if (access(filename, W_OK) == -1 && (flags & (O_WRONLY | O_CREAT)))
			ft_putstr_fd("ERROR: No write permission for file: ", 2);
		else
			ft_putstr_fd("ERROR: Unable to open file: ", 2);
		ft_putendl_fd(filename, 2);
	}
	return (fd);
}

char	*find_command_path(char *cmd, char **env)
{
	char	**paths;
	char	*cmd_path;
	int		i;

	paths = get_env_paths(env);
	if (!paths)
		return (NULL);
	cmd_path = NULL;
	i = 0;
	while (paths[i])
	{
		cmd_path = join_path(paths[i], cmd);
		if (access(cmd_path, X_OK) == 0)
			break ;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	free_split(paths);
	return (cmd_path);
}
