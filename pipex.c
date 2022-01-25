/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:50:14 by hqureshi          #+#    #+#             */
/*   Updated: 2022/01/25 14:56:48 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	excecute(char *argv, char **envp)
{
	char	*path;
	char	**my_cmdargs;

	my_cmdargs = ft_split(argv, ' ');
	path = parsing(my_cmdargs[0], envp);
	execve(path, my_cmdargs, envp);
	write(2, "Command: \"", 10);
	write(2, argv, ft_strlen(argv));
	write(2, "\" is not found\n", 15);
	exit (127);
}

void	child_process(int f1, int *end, char *cmd1, char **envp)
{
	dup2(end[1], STDOUT);
	close(end[0]);
	close(f1);
	excecute(cmd1, envp);
}

void	parent_process(int f2, int *end)
{
	waitpid(-1, NULL, 0);
	dup2(end[0], STDIN);
	close(end[1]);
	close(f2);
}

void	pipex(int f1, int f2, char *cmd1, char **envp)
{
	int		end[2];
	pid_t	parent;

	pipe(end);
	if (pipe(end) == -1)
		return (perror("Pipe failed..\n"));
	parent = fork();
	if (parent < 0)
		return (perror("Fork failed..\n"));
	if (!parent)
		child_process(f1, end, cmd1, envp);
	else
		parent_process(f2, end);
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;

	if (argc == 5)
	{
		f1 = check_file1(argv[1]);
		f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (f1 < 0 || f2 < 0)
			return (-1);
		dup2(f1, STDIN);
		dup2(f2, STDOUT);
		pipex(f1, f2, argv[2], envp);
		excecute(argv[3], envp);
		return (0);
	}
	else
		write(1, "Function failed\n", 15);
	return (1);
}
