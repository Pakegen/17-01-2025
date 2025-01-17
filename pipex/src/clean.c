/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:30:35 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/17 10:44:28 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cleanup_fds(int *fds, int fd_count)
{
	if (fd_count <= 0 || !fds)
		return ;
	if (fds[0] != -1)
		close(fds[0]);
	cleanup_fds(fds + 1, fd_count - 1);
}

void	cleanup_strings(char **to_free)
{
	if (!to_free || !*to_free)
		return ;
	free(to_free[0]);
	cleanup_strings(to_free + 1);
}

void	cleanup(int *fds, int fd_count, char **to_free)
{
	cleanup_fds(fds, fd_count);
	cleanup_strings(to_free);
}
