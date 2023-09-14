/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertstrtoar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:27:01 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/14 17:44:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
		ft_memcpy(new_str_ar[size], str_ar[size], ft_strlen(str_ar[size]));
		size++;
	}
}
