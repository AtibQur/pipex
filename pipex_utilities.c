/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:50:06 by hqureshi          #+#    #+#             */
/*   Updated: 2022/01/25 14:50:45 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i] != '\0')
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] +6);
		i++;
	}
	return (0);
}

char	*parsing(char *argv, char **envp)
{
	char	*path_from_env;
	char	**my_path;
	char	*ret;
	int		i;

	i = 0;
	path_from_env = ft_get_path(envp);
	my_path = ft_split(path_from_env, ':');
	while (my_path[i])
	{
		if (argv[0] == '/')
			ret = ft_strjoin(my_path[i], argv);
		else
			ret = ft_strjoin(ft_strjoin(my_path[i], "/"), argv);
		if (access(ret, F_OK) == 0)
			return (ret);
		free(ret);
		i++;
	}
	exit (127);
}

int	check_file1(char *argv)
{
	int	f1;

	if (access(argv, F_OK) == -1)
	{
		write(2, "no such file or directory: ", 27);
		write(2, argv, ft_strlen(argv));
		write(2, "\n", 1);
		return (-1);
	}
	f1 = open(argv, O_RDONLY);
	return (f1);
}
