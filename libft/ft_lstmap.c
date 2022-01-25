/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:51:46 by hqureshi          #+#    #+#             */
/*   Updated: 2022/01/21 14:51:47 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*ret;

	if (lst == 0)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		ret = ft_lstnew((*f)(lst->content));
		if (!ret)
		{
			ft_lstclear(&new_lst, del);
		}
		ft_lstadd_back(&new_lst, ret);
		lst = lst->next;
	}
	return (new_lst);
}
