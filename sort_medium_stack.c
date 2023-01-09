/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:13:57 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/08 17:59:57 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_min(int *a ,int *b , int *top , int *topb)
{
  int i; 
  int min;
  int pos;

  i = *top;
  min = a[*top];
  while(i > -1)
  {
    if(a[i] < min)
    {
      min = a[i];
      pos = i;
    }
    i--;
  }
  while(a[*top] != min)
  {
    if(pos < (*top/2))
      rra(a, *top);
    else 
      ra(a, *top);
  }
  pb(a, b, top, topb);
}
void sort_medium_stack(int *a ,int *b , int *top , int *topb)
{
  int i = 0;
  while(i < 2)
  {
    find_min(a,b, top, topb);
    i++;
  }
  sort_small_stack(a, *top);
   pa(a, b, top, topb);
   pa(a, b, top, topb);
    
}
      
