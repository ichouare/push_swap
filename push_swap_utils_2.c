/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:25:38 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/29 11:45:37 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	find_max(int *stack_b, int topb)
{
	int	pos;
	int	max;
	int	i;

	i = topb;
	pos = topb;
	max = stack_b[i];
	while (i >= 0)
	{
		if (stack_b[i] > max)
		{
			pos = i;
			max = stack_b[pos];
		}
		i--;
	}
	return (pos);
}

int	find_second_max( int *stack_b, int topb, int max, int pos_one)
{
	int	i;
	int	tmp;
	int	pos_two;

	if (topb == pos_one)
		i = (topb - 1);
	else
		i = topb;
	tmp = stack_b[i];
	pos_two = i;
	while (i >= 0)
	{
		if (stack_b[i] != max && stack_b[i] > tmp)
		{
			pos_two = i;
			tmp = stack_b[i];
		}
		i--;
	}
	return (pos_two);
}

void	push_biggest(t_list *tvars, int max, int biggest)
{
	if (biggest < (tvars->topb / 2))
	{
		while (tvars->b[tvars->topb] != max)
			rrb(tvars->b, tvars->topb);
	}
	else
	{
		while (tvars->b[tvars->topb] != max)
			rb(tvars->b, tvars->topb);
	}
	pa(tvars->a, tvars->b, &tvars->top, &tvars->topb);
}

void	push_max(t_list *tvars, int max, int biggest)
{
	if (biggest < (tvars->topb / 2))
	{
		while (tvars->b[tvars->topb] != max)
			rrb(tvars->b, tvars->topb);
	}
	else
	{
		while (tvars->b[tvars->topb] != max)
			rb(tvars->b, tvars->topb);
	}
	if (tvars->a[tvars->top] < tvars->b[tvars->topb])
	{
		pa(tvars->a, tvars->b, &tvars->top, &tvars->topb);
		sa(tvars->a, tvars->top);
	}
	else
		pa(tvars->a, tvars->b, &tvars->top, &tvars->topb);
}

int	push_in_a(t_list *tvars)
{
	int	i;
	int	pm;
	int	psm;

	pm = find_max(tvars->b, tvars->topb);
	psm = find_second_max(tvars->b, tvars->topb, tvars->b[pm], pm);
	tvars->max = tvars->b[pm];
	tvars->second_max = tvars->b[psm];
	tvars->biggest = find_biggest(tvars->topb, pm, psm);
	i = 0;
	while (i < 2)
	{
		if (tvars->biggest == psm)
		{
			push_biggest(tvars, tvars->second_max, psm);
			tvars->biggest = -2;
		}
		else
		{
			push_max(tvars, tvars->max, pm);
			tvars->biggest = psm;
		}
		i++;
	}	
	return (0);
}
