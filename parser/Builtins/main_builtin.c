/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:58:16 by nkietwee          #+#    #+#             */
/*   Updated: 2023/08/18 15:23:43 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
// echo
// cd
// pwd
export
unset
// env
exit
*/

int	ft_findstr(char *str, char *find, int len)
{
	int	i;

	i = 0;
	while (find[i] == str[i])
	{
		i++;
		if (i == len && str[i] == '\0')
			return(EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}


// void	ft_buildin(char *cmd, char **env)
void	ft_buildin(char *av, t_data *data)
{
	int	i;
	char	**tmp;
	// (void)env;

	i = 0;
	tmp = ft_split(av, ' ');
	printf("tmp[0] : %s\n" , tmp[0]);
	printf("tmp[1] : %s\n" , tmp[1]);
	/*edit tmp[1] -> tmp*/
	if (ft_findstr(tmp[0], "cd", 2) == EXIT_SUCCESS)
		ft_cd(tmp[1]);
	else if (ft_findstr(tmp[0], "pwd", 3) == EXIT_SUCCESS)
		ft_pwd();
	else if (ft_findstr(tmp[0], "env", 3) == EXIT_SUCCESS)
		ft_env(data);
	else if (ft_findstr(tmp[0], "echo", 4) == EXIT_SUCCESS)
		ft_echo(tmp);


}



void	ft_initdata(t_data *data, char **env)
{
	data->dict = ft_getenv(env);
	data->env_start = env;

}

int	main(int ac, char **av, char **env)
{
	t_data data;
	(void)ac;
	(void)av;
	char	*tmp;
	ft_initdata(&data, env);
	int	i;

	i = 0;
	printf("ft_buildin\n");
	// ft_buildin(av, env);
	while (1)
	{
		tmp = readline(BLU"nkietwee % "RESET);
		if (!tmp)
			return (0);
		add_history(tmp);
		// printf("history : %d\n" ,add_history(tmp));
		// printf("cmd : %s\n" ,tmp);
		if (ft_strlen(tmp) > 0)
			ft_buildin(tmp, &data);
		free(tmp);
	}
	// while (&data.dict[i])
	// {
	// 	// printf("key[%d] : %s\n", i, &data.dict[i]->key);
	// 	printf("value[%d] : %s\n", i, &data.dict[i]->key);
	// 	i++;
	// }

}