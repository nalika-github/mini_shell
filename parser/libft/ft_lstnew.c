/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:28:22 by ptungbun          #+#    #+#             */
/*   Updated: 2023/08/29 22:12:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void *data)t_rdr
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->next = 0;
	lst->data = data;
	return (lst);
}

typedef struct s_list
{
	void			*data; -> t_rdr
	struct s_list	*next; -> NULL
}					t_list;
