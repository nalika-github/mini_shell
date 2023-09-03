/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloca_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:24:16 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/03 14:25:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*getcmd_n_slide(t_list **lst)
{
	t_token token;
	t_list	*to_del_lst;
	char	*str;

	token = (*lst)->data;
	str = NULL;
	while (*lst && token->type != PIPE)
	{
		token = (*lst)->data;
		if (str == NULL)
			str = ft_strdup(token->str);
		else
			str = ft_strcat_n_free(str, token->str);
		*lst = (*lst)->next;
	}
	return (str);
}

int	get_str_to_table(t_minishell **ms)
{
	t_table	*table;
	t_token	*token;
	t_list	*lst;
	char	*c_ptr;

	(*ms)->table = NULL;
	table = (*ms)->table;
	while ((*ms)->lst)
	{
		if (table == NULL)
			table = ft_lstnew(getcmd_n_slide(&((*ms)->lst)));
		else
			ft_lstadd_back(&table, ft_lstnew(getcmd_n_slide(&((*ms)->lst))));
		token = ((*ms)->lst)->data;
		if (token->type == PIPE)

	}
}
