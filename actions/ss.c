/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:25:36 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/10 15:48:59 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ss(int *a, int topa, int *b, int topb)
{
	int	tmp;

	tmp = 0;
	if (topa <= 0 || topb <= 0)
		return (0);
	else
	{
		sa(a, topa);
		sb(b, topb);
	}
	write(1, "ss\n", 3);
	return (0);
}
