/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:13:21 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 15:28:40 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	child_single(t_shell *shell)
{
	char	**array;
	int		i;

	if (shell->heredoc_fd)
	{
		shell->heredoc_fd = open("tmp", O_RDONLY);
		dup2(shell->heredoc_fd, STDIN_FILENO);
	}
	if (shell->infile_fd && shell->infile_fd != -1)
		dup2(shell->infile_fd, STDIN_FILENO);
	if (shell->outfile_fd)
		dup2(shell->outfile_fd, STDOUT_FILENO);
	if (exec_builtin_2(shell, shell->line))
		exit(g_global.exit_code);
	array = command_parser(shell->line);
	if (cmd_exec(shell, array, shell->envp) == 1)
		return ;
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	exit(g_global.exit_code);
}

void	single_command(t_shell *shell)
{
	int		pid;
	int		status;

	status = 0;
	if (exec_builtin(shell, shell->line))
		return ;
	pid = fork();
	if (pid == 0)
		child_single(shell);
	waitpid(pid, &status, WUNTRACED);
	if (WIFEXITED(status))
		g_global.exit_code = WEXITSTATUS(status);
}

void	exec_single(t_shell *shell, t_line *tmp)
{
	if (!redirections_checker(shell, tmp->token, 1))
		return ;
	if (directory_checker(tmp->token) == 0)
		return ;
	single_command(shell);
	if (shell->infile_fd)
		close(shell->infile_fd);
	if (shell->outfile_fd)
		close(shell->outfile_fd);
	if (shell->heredoc_fd)
	{
		close(shell->heredoc_fd);
		unlink("tmp");
	}
	return ;
}
