/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atajima <atajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 11:36:32 by akihiro           #+#    #+#             */
/*   Updated: 2026/05/03 20:24:14 by atajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list  *tmp;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		del(tmp->content);
		free(tmp);
		tmp = (*lst)->next;
		*lst = tmp;
	}
}