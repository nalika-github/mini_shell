/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:24:16 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/14 20:20:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**getcmd_n_slide(t_list **lst)
{
	t_token *token;
	char	*str;
	char	**str_ar;

	token = (*lst)->data;
	str = NULL;
	while (*lst && token->type != PIPE)
	{
		if (token->type == CMD && token->type == ARG)
		{
			str = ft_strdup(token->str);
			str_ar = ft_insertstrtoar(str_ar, str);
			free(str);
		}
		*lst = (*lst)->next;
		if (*lst)
			token = (*lst)->data;
	}
	return (str_ar);
}

int	get_cmd_to_table(t_minishell **ms)
{
	t_table	*table;
	t_list	*lst;

	(*ms)->table = NULL;
	lst = (*ms)->lst;
	while (lst)
	{
		if ((*ms)->table == NULL)
			(*ms)->table = ft_lstnew(malloc(sizeof(t_table)));
		else
			ft_lstadd_back(&((*ms)->table), ft_lstnew(malloc(sizeof(t_table))));
		table = (ft_lstlast((*ms)->table))->data;
		(table->cmd) = getcmd_n_slide(&lst);
		if (lst && ((t_token *)((lst->data)))->type == PIPE)
			lst = lst->next;
	}
	return (0);
}

static void	getrdr_n_slide(t_list **rdr_lst, t_list **lst)
{
	t_token *token;
	t_rdr	*rdr;
	int		i;

	i = 0;
	while (*lst && token->type != PIPE)
	{
		token = (*lst)->data;
		if (token->type == INFILE || token->type == OUTFILE || \
		token->type == HEREDOC || token->type == APPEND)
		{
			if(i == 0)
				*rdr_lst = ft_lstnew(malloc(sizeof(t_rdr)));
			else
				ft_lstadd_back(rdr_lst, ft_lstnew(malloc(sizeof(t_rdr))));
			rdr = (ft_lstlast(*rdr_lst))->data;
			rdr->type = token->type;
			rdr->file = token->str;
			i++;
		}
		*lst = (*lst)->next;
	}
	if (token->type == PIPE)
		*lst = (*lst)->next;
}

int	get_rdr_to_table(t_minishell **ms)
{
	t_list	*table_lst;
	t_list	*lst;
	t_list	*rdr_lst;

	table_lst = (*ms)->table;
	lst = (*ms)->lst;
	while(table_lst)
	{
		rdr_lst = (((t_table *)(table_lst->data))->rdr);
		getrdr_n_slide(&rdr_lst, &lst);
		table_lst = table_lst->next;
	}
	return (0);
}
