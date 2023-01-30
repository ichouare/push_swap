/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:13:57 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/28 11:39:26 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(int *a, int *b, int *top, int *topb)
{
	int	i;
	int	min;
	int	pos;

	i = *top;
	min = a[*top];
	while (i > -1)
	{
		if (a[i] < min)
		{
			min = a[i];
			pos = i;
		}
	i--;
	}
	while (a[*top] != min)
	{
		if (pos < (*top / 2))
			rra(a, *top);
		else
			ra(a, *top);
	}
	pb(a, b, top, topb);
}

void	sort_medium_stack(int *a, int *b, int *top, int *topb)
{
	int	i;
	int	k;

	i = 0;
	if (*top == 3)
		k = 1;
	else
		k = 2;
	while (i < k)
	{
		find_min(a, b, top, topb);
		i++;
	}
	sort_small_stack(a, *top);
	i = 0;
	while (i < k)
	{
		pa(a, b, top, topb);
		i++;
	}
}
