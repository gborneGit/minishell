/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:26:25 by gborne            #+#    #+#             */
/*   Updated: 2022/07/30 11:48:06 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	echo(t_cmd *cmd)
{
	char	*str;
	int		i;
	int		newline;

	i = 1;
	newline = 1;
	if (cmd->arg[i] && ft_strcmp(cmd->arg[i], "-n") == 0)
	{
		newline = 0;
		i++;
	}
	if (cmd->arg[i])
	{
		str = ft_strdup(cmd->arg[i]);
		while (cmd->arg[++i])
		{
			str = ft_strjoin(str, " ");
			str = ft_strjoin(str, cmd->arg[i]);
		}
		if (newline)
			str = ft_strjoin(str, "\n");
		write(1, str, ft_strlen(str));
		free(str);
	}
	else
		if (newline)
			write(1, "\n", 2);
}