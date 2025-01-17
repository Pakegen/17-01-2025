/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:08:03 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/17 09:58:13 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../utils/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

// Définitions des constantes
# define MAX_COMMANDS 100 // Limite maximale du nombre de commandes

// Structure principale
typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	**cmds;
	int		cmd_count;
	char	**env;
}	t_pipex;

void	pipex(t_pipex *data);
void	execute_pipeline(t_pipex *data, int cmd_index, int input_fd);
void	create_child(int input_fd, int output_fd, char *cmd, char **env);
void	redirect(int input_fd, int output_fd);
void	run_command(char *cmd, char **env);
void	cleanup(int *fds, int fd_count, char **to_free);
void	error_exit(const char *msg);
int		open_file(char *filename, int flags, int mode);
char	*find_command_path(char *cmd, char **env);
char	**get_env_paths(char **env);
char	*join_path(char *path, char *cmd);
void	free_split(char **split);
int		is_valid_string(char *str);
void	wait_for_all_children(void);

#endif
