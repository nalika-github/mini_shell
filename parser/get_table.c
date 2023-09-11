/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:24:16 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/07 22:49:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*getcmd_n_slide(t_list **lst)
{
	t_token token;
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

int	get_cmd_to_table(t_minishell **ms)
{
	t_table	*table;
	t_token	*token;
	t_list	*node;
	t_list	*lst;

	(*ms)->table = NULL;
	lst = (*ms)->lst;
	while (lst)
	{
		node = ft_lstnew(malloc(sizeof(t_table)));
		if ((*ms)->table == NULL)
			(*ms)->table = node;
		else
			ft_lstadd_back(&((*ms)->table), node);
		table = (ft_lstlast((*ms)->table))->data;
		table->cmd = getcmd_n_slide(&lst);
		token = lst->data;
		if (token->type == PIPE)
			lst = lst->next;
	}
}

static void	getrdr_n_slide(t_list **rdr_lst, t_list **lst)
{
	t_token token;
	t_rdr	rdr;

	rdr = (*rdr_lst)->data;
	token = (*lst)->data;
	while (*lst && token->type != PIPE)
	{
		if (token->type == INFILE || token->type == OUTFILE || \
		token->type == HEREDOC || token->type == APPEND)
		{
			rdr->type = token->type;
			*(rdr->file) = *(token->str);
			rdr_lst = rdr_lst->next;
			rdr = (*rdr_lst)->data;
		}
		lst = lst->next;
		token = (*lst)->data;
	}
	if (token->type == PIPE)
		*lst = (*lst)->next;
}

int	get_rdr_to_table(t_minishell **ms)
{
	t_list	table_lst;
	t_list	lst;
	t_list	rdr_lst;

	table_lst = (*ms)->table;
	lst = (*ms)->lst;
	while(table_lst)
	{
		rdr_lst = ((t_table *)(table_lst->data)->rdr);
		getrdr_n_slide(&rdr_lst, &lst);
		table_lst = table_lst->next;
	}
}
