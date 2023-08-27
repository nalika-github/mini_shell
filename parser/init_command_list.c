/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:52:18 by ptungbun          #+#    #+#             */
/*   Updated: 2023/08/26 20:28:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	slide_n_decide(t_list *lst, char *line)
{
	while (*line)
	{
		if (lst == NULL)
			return (0);
		else if (ft_isquote(*line))
			return (2);
		else if (ft_ismetachar(*line))
			return (3);
		else if (!ft_isspace(*line))
			return (1);
		line++;
	}
	return (-1);
}

int	init_command_list(t_minishell **ms, char *line)
{
	t_list	*lst;
	char	*ptr_line;
	int		index;

	ptr_line = line;
	lst = NULL;
	while (*ptr_line)
	{
		index = slide_n_decide(lst, ptr_line);
		if (index == -1)
			return (1);
		grab_to_lst(&lst, &ptr_line, index);
	}
	(*ms)->lst = lst;
	return (0);
}
