/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertstrtoar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:27:01 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/14 18:12:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	freestrar(char **str_ar)
{
	size_t	i;

	i = 0;
	while (str_ar[i])
	{
		free(str_ar[i]);
		i++;
	}
	free(str_ar);
}

char	**ft_insertstrtoar(char **str_ar, char *insert_str)
{
	size_t	size;
	char	**new_str_ar;

	size = 0;
	while(str_ar[size])
		size++;
	new_str_ar = ft_calloc(sizeof(char *), size + 1);
	size = 0;
	while(str_ar[size])
	{
		new_str_ar[size] = ft_strdup(str_ar[size]);
		size++;
	}
	new_str_ar[size] = ft_strdup(insert_str);
	freestrar(str_ar);
	return (new_str_ar);
}
