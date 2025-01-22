/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:50:15 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/29 21:43:18 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!new && lst)
		ft_lstclear(lst, NULL);
	if (!*lst)
	{
		*lst = new ;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}
