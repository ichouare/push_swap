/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:43:54 by ichouare          #+#    #+#             */
/*   Updated: 2023/02/01 16:27:16 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	fetch_biggest(int pos_max, int pos_smax, int topb)
{
	if ((pos_max > (topb / 2)) && (pos_smax <= (topb / 2)))
	{
		if ((pos_max - topb) < (pos_smax + 1))
			return (pos_max);
		else
			return (pos_smax);
	}
	else if ((pos_max < (topb / 2)) && (pos_smax >= (topb / 2)))
	{
		if ((pos_smax - topb) > (pos_max + 1))
			return (pos_max);
		else
			return (pos_smax);
	}
	else
		return (pos_max);
}

int	find_biggest(int topb, int pos_max, int pos_smax)
{
	if ((pos_max < (topb / 2)) && (pos_smax <= (topb / 2)))
	{
		if (pos_max < pos_smax)
			return (pos_max);
		else
			return (pos_smax);
	}
	else if ((pos_max > (topb / 2)) && (pos_smax >= (topb / 2)))
	{
		if (pos_max > pos_smax)
			return (pos_max);
		else
			return (pos_smax);
	}
	else
		return (fetch_biggest(pos_max, pos_smax, topb));
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

int	second_scan(int *stack_a, int *Chunks, int j, int top)
{
	int	i;

	i = top;
	while (i >= 0)
	{
		if (stack_a[i] <= Chunks[j])
			return (i);
		i--;
	}
	return (-1);
}

void	sort_large_stack(t_list *tvars)
{
	int	*chunks;
	int	j;
	int	sz;
	int	k;
	int	tmp;

	sz = tvars->top;
	chunks = sort_temp(tvars->a, tvars->top);
	j = 0;
	if (sz < 150)
		k = 5;
	else
		k = 9;
	while (j <= sz)
	{
		tmp = j;
		j += (sz / k);
		tvars->half_chunks = (tmp + j) / 2;
		push_in_b(tvars, j, chunks);
	}
	while (tvars->top > -1)
		pb(tvars->a, tvars->b, &tvars->top, &tvars->topb);
	while (tvars->topb > -1)
		push_in_a(tvars);
	free (chunks);
}
