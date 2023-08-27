/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:50:33 by nkietwee          #+#    #+#             */
/*   Updated: 2023/08/20 10:50:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_dict	**ft_getnewenv(t_dict **old_dict, char **env)
{
	int	i;
	int	len;
	char **tmp_env;
	t_dict	**dict;
	char *tmp_pwd;

	if (old_dict)
		ft_free(old_dict);
	i = 0;
	len = ft_cntline(env);
	dict = malloc(sizeof(t_dict *) * (len + 1));
	if (!dict)
		return (0);
	while (i < len)
	{
		dict[i] = malloc(sizeof(t_dict));
		if (!dict[i])
			return (0);
		tmp_env = ft_split(env[i], '=');
		if (tmp_env[0])
			dict[i]->key = ft_strdup(tmp_env[0]);
		else
			dict[i]->key = NULL;
		if (tmp_env[1] && ft_findstr(tmp_env[0], "PWD", 3) == EXIT_SUCCESS)
		{
			tmp_pwd = getenv("PWD");
			dict[i]->value = ft_strdup(tmp_pwd);
		}
		else if (tmp_env[1])
			dict[i]->value = ft_strdup(tmp_env[1]);
		else
			dict[i]->value = "";
		i++;
	}
	dict[i] = NULL;
	return (dict);
}

t_dict	**ft_getenv(char **env)
{
	int	i;
	int	len;
	char **tmp_env;
	t_dict	**dict;

	i = 0;
	len = ft_cntline(env);
	dict = malloc(sizeof(t_dict *) * (len + 1));
	if (!dict)
		return (0);
	while (i < len)
	{
		dict[i] = malloc(sizeof(t_dict));
		if (!dict[i])
			return (0);
		tmp_env = ft_split(env[i], '=');
		if (tmp_env[0])
		{
			dict[i]->key = ft_strdup(tmp_env[0]);
			// if (dict[i]->key == "PWD")
			// 	dict[i]->value = getcwd
		}
		else
			dict[i]->key = NULL;
		if (tmp_env[1])
			dict[i]->value = ft_strdup(tmp_env[1]);
		else
			dict[i]->value = "";
		i++;
	}
	dict[i] = NULL;
	return (dict);
}
