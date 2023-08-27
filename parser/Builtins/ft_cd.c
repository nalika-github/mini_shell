/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:32:39 by nkietwee          #+#    #+#             */
/*   Updated: 2023/08/18 15:20:37 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*update env*/
void	ft_cd(char *str)
{
	char	pre_path[128];
	char	*tmp;
	int		errno;

	errno = 0;
	printf("fn_cd\n");
	printf("str : %s\n" ,str);
	// if (str)
	// 	ft_getnewenv(NULL, data->env_start);

	if (str == NULL || ft_findstr(str, "~", 1) == EXIT_SUCCESS)
		str = getenv("HOME");
	// if (ft_strcmp(str, "-") == EXIT_SUCCESS) // left test
	// {
	//     tmp = getcwd(pre_path, 128);
	//     if (!tmp)
	//         return ;
	//     chdir(pre_path);
	// }
	if (access(str, F_OK) == 0)
	{
		if (access(str, R_OK | F_OK) == 0)
			chdir(str);
		else
			printf("Err\n");
		// ft_prterr_builtins(CANNT_OPEN, "cd", str, errno);
	}
	else
		printf("Err\n");
	// ft_prterr_builtins(PER_DN, "cd",str, errno);

}