/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:50:16 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/14 17:52:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_dict_value	**ft_getvalue_env(char **env)
{
	int	line_env;
	t_dict_value **tmp_dict;
	char	**tmp_env;
	int	i;

	line_env = ft_cntstr(env);
	i = 0;
	tmp_dict = malloc(sizeof(t_dict_value *) * (line_env + 1));
	if (!tmp_dict)
		return (NULL);
	while (i < line_env)
	{
		tmp_dict[i] = malloc(sizeof(t_dict_value));
		tmp_env = ft_split(env[i], '=');
		if (tmp_env[0])
			tmp_dict[i]->key = ft_strdup(tmp_env[0]);
		else
			tmp_dict[i]->key = ft_strdup("");
		if (tmp_env[1])
			tmp_dict[i]->value = ft_strdup(tmp_env[1]);
		else
			tmp_dict[i]->value = NULL;
		i++;
	}
	return (tmp_dict);
}

t_dict	*getenv(char **env)
{
	int			i;
	int			len;
	t_dict_value	**tmp_env;
	t_dict *tmp;
	t_dict	*dict;

	i = 0;
	tmp_env = ft_getvalue_env(env);
	len = ft_cntstr(env);
	dict = NULL;
	while (i < len)
	{
		tmp = ft_lstnew(tmp_env[i]);
		ft_lstadd_back(&dict, tmp);
		i++;
	}
	return(dict);
}
