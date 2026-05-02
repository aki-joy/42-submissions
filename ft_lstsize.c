/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihiro <akihiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:47:57 by akihiro           #+#    #+#             */
/*   Updated: 2026/05/01 14:57:42 by akihiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list  new;

    new = malloc(t_list);
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}