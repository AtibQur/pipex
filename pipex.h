/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:49:56 by hqureshi          #+#    #+#             */
/*   Updated: 2022/01/21 15:01:04 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"

# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>

# define STDIN 0
# define STDOUT 1

void	pipex(int f1, int f2, char *cmd1, char **envp);
void	parent_process(int f2, int *end);
void	child_procces(int f1, int end[], char **argv, char *envp[]);
void	excecute(char *argv, char **envp);

int		main(int argc, char **argv, char *envp[]);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		check_file1(char *argv);

char	*parsing(char *argv, char **envp);
char	*ft_get_path(char *envp[]);
#endif
