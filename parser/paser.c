/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paser.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:52:19 by ptungbun          #+#    #+#             */
/*   Updated: 2023/08/27 22:37:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	error_exit(t_minishell *ms)
{
	t_list	*lst;

	lst = ms->lst;
	printf("error\n");
	ft_lstclear(&lst, &free);
	return (1);
}

int	paser(t_minishell *ms)
{
	if (expand_var(&ms))
		return (error_exit(ms));
	// if (sanitize(&ms))
	// 	return (error_exit(ms));
	if (contain_cmd_to_table(&ms))
		return (error_exit(ms)); 
	return (1);
}
