/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 03:11:12 by ptungbun          #+#    #+#             */
/*   Updated: 2022/03/01 03:11:14 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s)
{
	char	*room;
	size_t	len;

	len = ft_strlen(s) + 1;
	room = malloc(sizeof(char) * len);
	if (!room)
		return (0);
	return (ft_memcpy(room, s, len));
}
