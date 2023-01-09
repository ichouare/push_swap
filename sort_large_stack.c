/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:43:54 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/08 19:30:05 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_in_a(int *stack_a ,  int * stack_b , int *top , int *topb)
{
    int i;
    int max;
    int pos;

    i = *topb;
    max = stack_b[*topb];
    pos = *topb;
    while( i >= 0)
    {
        if(stack_b[i] > max)
        {
            max = stack_b[i];
            pos = i;
        }
        i--;
    }
    while(stack_b[*topb] != max)
    {
        if(pos < (*topb/2))
            rrb(stack_b , *topb);
        else 
            rb(stack_b , *topb);   
    }
    pa(stack_a , stack_b , top , topb);
     return(0);
    }


int first_Scan(int *stack_a ,int  *Chunks , int j , int top)
{
    int i ;

    i = 0;
    
     while(i <= top)
        {
            if(stack_a[i] <= Chunks[j])
            {
                return(i);            
            }
        i++;
        }
        return(-1);
        

}

int check_num(int *stack_a ,int *Chunks , int top , int j)
{
    int i;

    i = 0;
   while( i <= top)
    {
        if( stack_a[i] <= Chunks[j])
            return(1);
        i++;
    }
    return(0);
}

void sort_large_stack(int *stack_a, int *stack_b, int *top, int   *topb)
{
   int hold_first;
   int hold_second;
    int first_spot;
    int second_spot;
    int *tab_temp;
    int *Chunk;
    int j;
    int i;
    int sz;
    int k;
    
    sz = *top;
    Chunk = sort_temp(stack_a , *top);
    i = 0;
    j= 0;
    hold_first = -1;
    hold_second = -1;
    j = 0;
    if (sz < 150)
        k = 5;
    else 
        k = 10;
    while ( j <= sz)
    {
        first_spot = 0;
        while(check_num(stack_a, Chunk, *top, j) != 0)  
        {
            first_spot = first_Scan(stack_a, Chunk, j , *top); 
            hold_first = stack_a[first_spot];
            if(first_spot <= (sz/2))
            {
                    while(stack_a[*top] != hold_first)
                    {
                        rra(stack_a , *top);
                    }
            } 
            else if(first_spot > (sz/2))
            {
                    while(stack_a[*top] != hold_first)
                    {
                        ra(stack_a , *top);
                    }
            } 
        pb(stack_a , stack_b, top , topb);
         } 
        j += sz/k;
    }
    while(*top > -1)
    {
        pb(stack_a , stack_b, top , topb);

    }
    while(*topb > -1)
    {
    push_in_a(stack_a , stack_b, top , topb);
    }
    free(Chunk);
    }



