/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:32:52 by nkietwee          #+#    #+#             */
/*   Updated: 2023/08/18 15:50:29 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_echo(char **str)
{
	int	i;
	int	no_nl;

	i = 1; // i = 0 ->echo
	no_nl = 0;
	if (ft_findstr(str[1], "-n", 2) == EXIT_SUCCESS)
	{
		no_nl = 1;
		i = 2;
	}
	while (str[i])
	{
		ft_putstr_fd(str[i], STDOUT_FILENO);
		i++;
		if (!str[i])
			break;
		ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (no_nl == 0)
		write(STDOUT_FILENO, "\n", 1);
}