/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:43:41 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/10 15:36:45 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(int *a, int topa, int *b, int topb)
{
	ra(a, topa);
	rb(b, topb);
	write(1, "rr\n", 3);
}
