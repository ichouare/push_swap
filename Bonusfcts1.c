/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonusfcts1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:31:28 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/09 20:36:11 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int  sa(int *a, int top)
{   int tmp;

    tmp = 0;
    if(top <= 0)
        return (0);
    else{
        tmp = a[top];
        a[top] = a[top - 1];
        a[top - 1] = tmp; 
    }
     return (0);
}

int  sb(int *b, int top)
{   int tmp;

    tmp = 0;
    if(top <= 0)
        return (0);
    else{
        tmp = b[top];
        b[top] = b[top - 1];
        b[top - 1] = tmp; 
    }
     return (0);
}

int  ss(int *a, int topa , int *b , int topb)
{   int tmp;

    tmp = 0;
    if(topa <= 0 || topb <= 0)
        return (0);
    else{
        sa(a, topa);
        sb(b, topb);
    }
    return (0);
}

int pa(int *a, int *b , int *topa , int *topb)
{
    if(*topb == -1)
        return (0);
    *topa = *topa + 1;
    a[*topa] =  b[*topb];
    b[*topb] = 0;
    *topb = *topb -  1;
    return(0);
}

int pb(int *a, int *b , int *topa , int *topb)
{
    if(*topa == -1)
        return (0);
    *topb = *topb + 1;
    b[*topb] =  a[*topa];
    *topa = *topa - 1;
    return(0);
}


int rrr(int *a , int topa ,int *b , int topb)
{
    rra(a, topa);
    rrb(b , topb);
    return (0);
}
