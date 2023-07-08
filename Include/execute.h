/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:41:48 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/26 00:15:37 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

void    ft_initdata(void);
int     ft_main(char *find , char **env);
int     ft_findstr(char *str, char *find, int len);
int     ft_strcmp(char *s1, char *s2);


//pwd
void    ft_pwd(void);
#endif