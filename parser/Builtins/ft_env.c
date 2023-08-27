/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:32:57 by nkietwee          #+#    #+#             */
/*   Updated: 2023/08/18 14:43:20 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* update oldpwd pwd
getcwd
*/

void	ft_env(t_data *data)
{
	int	i;
	t_dict **new_dict;

	i = 0;
	new_dict = ft_getnewenv(NULL , data->env_start);
	while (new_dict[i])
	{
		printf("%s", new_dict[i]->key);
		printf("=");
		printf("%s\n", new_dict[i]->value);
		i++;
	}
	printf("END\n");
}