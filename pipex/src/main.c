/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:08:27 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 21:40:04 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_valid_string(char *str)
{
	if (!str || str[0] == '\0')
	{
		ft_putendl_fd("ERROR, INVALID ARGUMENT\n", 2);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	data;

	if (ac < 5)
	{
		ft_putendl_fd("ERROR, NOT ENOUGHT ARGUMENTS\n", 2);
		return (1);
	}
	if (!is_valid_string(av[1]) || !is_valid_string(av[ac - 1]))
	{
		ft_putendl_fd("ERROR: Invalid infile or outfile\n", 2);
		return (1);
	}
	data.infile = av[1];
	data.outfile = av[ac - 1];
	data.cmds = &av[2];
	data.cmd_count = ac - 3;
	data.env = env;
	if (data.cmd_count > 100)
	{
		ft_putendl_fd("ERROR, TOO MANY (max 100)\n", 2);
		return (1);
	}
	pipex(&data);
	return (0);
}
