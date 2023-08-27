/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalide_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:01:31 by ptungbun          #+#    #+#             */
/*   Updated: 2023/08/03 10:41:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminishell.h"

int	ft_isvalide_quote(char *str, char quote)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (str[i] == quote)
			return (1);
		i++;
	}
	return(0);
}
