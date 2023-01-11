/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:43:54 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/11 17:12:17 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_in_a(int *stack_a, int *stack_b, int *top, int *topb)
{
	int	i;
	int	max;
	int	pos;

	i = *topb;
	max = stack_b[*topb];
	pos = *topb;
	while (i >= 0)
	{
		if (stack_b[i] > max)
		{
			max = stack_b[i];
			pos = i;
		}
		i--;
	}
	while (stack_b[*topb] != max)
	{
		if (pos < (*topb / 2))
			rrb(stack_b, *topb);
		else
			rb(stack_b, *topb);
	}
	pa(stack_a, stack_b, top, topb);
	return (0);
}

int	first_scan(int *stack_a, int *Chunks, int j, int top)
{
	int	i;

	i = 0;
	while (i <= top)
	{
		if (stack_a[i] <= Chunks[j])
			return (i);
		i++;
	}
	return (-1);
}

int	check_num(int *stack_a, int *Chunks, int top, int j)
{
	int	i;

	i = 0;
	while (i <= top)
	{
		if (stack_a[i] <= Chunks[j])
			return (1);
		i++;
	}
	return (0);
}

void	push_in_b(t_list *tvars, int j, int sz, int *chunks)
{
	int	first_spot;
	int	hold_first;

	first_spot = 0;
	hold_first = -1;
	while (check_num(tvars->a, chunks, tvars->top, j) != 0)
	{
		first_spot = first_scan(tvars->a, chunks, j, tvars->top);
		hold_first = tvars->a[first_spot];
		if (first_spot <= (tvars->top / 2))
		{
			while (tvars->a[tvars->top] != hold_first)
				rra(tvars->a, tvars->top);
		}
		else if (first_spot > (tvars->top / 2))
		{
			while (tvars->a[tvars->top] != hold_first)
				ra(tvars->a, tvars->top);
		}
		pb(tvars->a, tvars->b, &tvars->top, &tvars->topb);
	}
}

void	sort_large_stack(t_list *tvars)
{
	int	*tab_temp;
	int	*chunks;
	int	j;
	int	sz;
	int	k;

	sz = tvars->top;
	chunks = sort_temp(tvars->a, tvars->top);
	j = 0;
	if (sz < 150)
		k = 5;
	else
		k = 10;
	while (j <= sz)
	{
		push_in_b(tvars, j, sz, chunks);
		j += (sz / k);
	}
	while (tvars->top > -1)
		pb(tvars->a, tvars->b, &tvars->top, &tvars->topb);
	while (tvars->topb > -1)
		push_in_a(tvars->a, tvars->b, &tvars->top, &tvars->topb);
	free (chunks);
}
