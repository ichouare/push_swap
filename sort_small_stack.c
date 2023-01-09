/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:19:19 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/08 18:41:30 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void sort_small_stack(int *a , int top)
{
 

 if(a[top] > a[1] &&  a[top] > a[0] && a[1] > a[0])
   {
        sa(a , top);
        rra(a , top);
   }
  else if(a[top] > a[1] && a[top] > a[0])
   {
     ra(a , top);
     return ;
   }   
   else if(a[top] > a[1] &&  a[top] < a[0])
   {
     sa(a , top);
     return ;
   }
   
else if (a[top] < a[1] && a[top] < a[0] && a[1] > a[0])
{
     sa(a , top);
     ra(a , top); 
        return ;
}  
else if(a[top] < a[1]  && a[top] > a[0])
{
     rra(a , top);   
}
}