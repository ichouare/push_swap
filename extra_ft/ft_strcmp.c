/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:33:41 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/29 11:51:36 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp( char *p1, char *p2, int len )
{	
	int	i;

	i = 0;
	if (!p1 && !p2)
		return (1);
	else if (ft_strlen(p1) == ft_strlen(p2))
	{
		while ((p1[i] && p2[i]))
		{
			if (p1[i] > p2[i])
				return (1);
			if (p1[i] < p2[i])
				return (1);
			i++;
			len--;
		}
		return (0);
	}
	return (1);
}
