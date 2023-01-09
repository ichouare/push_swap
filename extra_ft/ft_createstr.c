/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:32:13 by ichouare          #+#    #+#             */
/*   Updated: 2022/12/28 13:49:07 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

ele	*ft_lstnew(int *content)
{
    ele *lst;

    lst = NULL;
    lst = (ele *)malloc(sizeof(ele));
    if (!lst) 
        return (NULL);
    lst->data = *content;
    lst->next = NULL;
    return (lst);
}