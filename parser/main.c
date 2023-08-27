/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:44:05 by ptungbun          #+#    #+#             */
/*   Updated: 2023/07/11 18:44:19 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	init_minishell(t_minishell *env, char **input_minishell, int *ac, char ***av)
// {
// 	(void)ac;
// 	(void)av;
// 	env->dict = ft_getenv(input_minishell);
// }

int main(int ac, char **av, char **env)
{
	char 		*line;
	char 		*prompt_str;
	t_minishell	ms;

	// init_ms(&ms, env, &ac, &av);
	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		// รับ signal ใน while loop
		prompt_str = prompt();
		line = readline(prompt_str); // รับค่า control d ผ่าน readline
		free (prompt_str);
		if (!line)
			return (1);
		add_history(line);
		if(lexer(line, &ms))
			continue ;
		// paser(&ms);
		// excute(&ms); รับ signal ใน while loop
		// free_token(&ms.token);
	}
	// free_token(&ms.token); exit print
	free(&line);
	free(&ms);
	return (0);
}
