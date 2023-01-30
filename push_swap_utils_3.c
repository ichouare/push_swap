/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:33:09 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/29 11:48:36 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

void	push_in_b(t_list *tvars, int j, int *chunks)
{
	t_pos	find_ps;

	find_ps.first_spot = 0;
	find_ps.second_spot = 0;
	find_ps.biggest = -1;
	while (check_num(tvars->a, chunks, tvars->top, j) != 0)
	{
		find_ps.first_spot = first_scan(tvars->a, chunks, j, tvars->top);
		find_ps.second_spot = second_scan(tvars->a, chunks, j, tvars->top);
		find_ps.biggest = find_biggest(tvars->top,
				find_ps.first_spot, find_ps.second_spot);
		find_ps.hold_first = tvars->a[find_ps.biggest];
		if (find_ps.hold_first > chunks[tvars->half_chunks])
		{
			handler_bottom(tvars, &find_ps);
		}
		else
			handler_top(tvars, &find_ps);
	}
}

void	handler_top(t_list *tvars, t_pos *find_ps)
{
	if (find_ps->biggest < (tvars->top / 2))
	{
		while (tvars->a[tvars->top] != find_ps->hold_first)
			rra(tvars->a, tvars->top);
	}
	else
	{
		while (tvars->a[tvars->top] != find_ps->hold_first)
			ra(tvars->a, tvars->top);
	}
	pb(tvars->a, tvars->b, &tvars->top, &tvars->topb);
}

void	handler_bottom(t_list *tvars, t_pos *find_ps)
{
	if (find_ps->biggest < (tvars->top / 2))
	{
		while (tvars->a[tvars->top] != find_ps->hold_first)
			rra(tvars->a, tvars->top);
	}
	else
	{
		while (tvars->a[tvars->top] != find_ps->hold_first)
			ra(tvars->a, tvars->top);
	}
	pb(tvars->a, tvars->b, &tvars->top, &tvars->topb);
	rb(tvars->b, tvars->topb);
}
