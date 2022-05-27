/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:54:40 by mbastard          #+#    #+#             */
/*   Updated: 2022/05/27 19:12:58 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// write "exit\n" and exit the program
void	end()
{
	write(1, "exit\n", 5);
	exit(0);
}

void	clear_cmd(void *content)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)content;
	free(cmd->cmd);
	free_tab(cmd->arg);
}

void	clear_data(t_data *data)
{
	ft_lstclear(&data->cmds, &clear_cmd);
	free(data->cmds);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_data	data;

	//recover_history(history_fd);
	while (argv && argc)
	{
		input = readline(CYELLOW "minishell$ " RESET);
		if (ft_strlen(input) > 0)
			//manage_history(input);
		if (!ft_strncmp(input, "exit", 4))
		{
			clear_data(&data);
			exit(0);
		}

		if (ft_strlen(input) > 0)
		{
			get_cmds(input, &data);
			free(input);
			//print_cmds(data.cmds);
			exec(&data, envp);
			clear_data(&data);
		}
	}
	return (0);
}

/*void manage_history(char *input)
{
	int		history_fd;

	history_fd = open("tmp/history", O_RDWR | O_CREAT | O_APPEND, 0777);
	add_history(input);
	ft_putendl_fd(input, history_fd);
	close(history_fd);
}

void	recover_history(int fd)
{
	int		i;
	size_t	len;
	char	*commands;
	char	**history;

	i = -1;
	len = 0;
	commands = get_next_line(fd);
	if (commands)
	{
		while (len != ft_strlen(commands))
		{
			len = ft_strlen(commands);
			commands = ft_strjoin(commands, get_next_line(fd));
		}
		write(1, "test\n", 5);
		history = ft_split(commands, '\n');
		if (history)
			while (history[++i])
				add_history(history[i]);
		free_tab(history);
	}
	free(commands);
}
*/
