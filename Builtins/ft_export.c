/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:48:06 by nkietwee          #+#    #+#             */
/*   Updated: 2023/09/17 02:17:31 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_swap(t_dict *dict)
{
		char *tmp_key=NULL;
		char *tmp_value=NULL;

		tmp_key = dict->next->tmp_dict->key;
		tmp_value = dict->next->tmp_dict->value;

		dict->next->tmp_dict->key = dict->tmp_dict->key;
		dict->next->tmp_dict->value = dict->tmp_dict->value;

		dict->tmp_dict->key = tmp_key;
		dict->tmp_dict->value = tmp_value;

}

void	ft_lstascend(t_dict *dict)
{
	int	len;
	t_dict *head;
	t_dict *head2;

	len = ft_lstsize_dict(dict);
	head2 = dict; // for print
	int	i = 0;
	head = dict;
	int size = ft_lstsize_dict(dict);
	while (i < size - 1)
	{
		dict = head;
		while (dict && dict->next != NULL)
		{
			if (ft_strcmp(dict->tmp_dict->key , dict->next->tmp_dict->key) > 0)
				ft_swap(dict);
			else
				dict = dict->next ;
		}
		i++;
	}
	ft_prtdict(head2);
	//freeloop
}


/* convert env to tmp_env */
void	ft_printvalue_ep(char **env)
{
	t_dict *dict;

	dict = ft_getenv(env);
	ft_lstascend(dict);

}

/* check first character of variable(key) */
void	ft_checkname(char **cmd)
{
	int	i;


	i = 1; // i = 0 is export
	while (cmd[i])
	{
		if (ft_isalpha(cmd[i][0]) == EXIT_FAILURE)
		{
			ft_putstr_fd("bash: export: `", STDERR_FILENO);
			ft_putstr_fd(cmd[i], STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier", STDOUT_FILENO);
		}
		i++;
	}
	// ft_exit()
}


//return t_dict for print env
t_dict	*ft_export(char **cmd, char **env)
{
	int	len;
	t_dict *tmp_export;

	ft_checkname(cmd); //check first character of variable(key)
	len = ft_cntstr(cmd);
	printf("len : %d\n", len);
	if (len == 2) // fixed 2 -> 1 (export no arg)
		ft_printvalue_ep(env);
	if (len > 2) // fixed 2 -> 1 (export with arg)
		tmp_export =  ft_addvalueexport(cmd, env); // left assign value

	// exit(0);
	return (tmp_export);
}