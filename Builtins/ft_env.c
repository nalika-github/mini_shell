/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 00:12:52 by nkietwee          #+#    #+#             */
/*   Updated: 2023/07/02 16:31:06 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

/*get env ???*/
void    ft_env(char **env ,char **name)
{
    int i;

    i = 0;
    while (env[i])
    {
        printf("%s\n" ,env[i]);
        i++;
    }
    // i = 0;
    // if (name)
    // {
    //    printf("%s\n" ,name[i]);
    //    i++;
    // }
}