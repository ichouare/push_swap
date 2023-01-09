/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:43:33 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/05 13:20:03 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
int *sort_temp(int *tab , int top)
{
    int i;
    int max;
    int j;
    int *temp_tab = (int *) malloc(top * sizeof(int));
   
   i = 0;
   while(i <= top)
   {
        temp_tab[i] = tab[i];
        i++;
   }
   i = 1;
   while( i <= top)
   {
    max = temp_tab[i];
    j = i - 1;
    while( j >= 0 && temp_tab[j] > max)
    {
        temp_tab[j + 1] = temp_tab[j];
        j -=1;
        
    }
    temp_tab[j + 1] = max; 
    i++;
   }
  
    
    return (temp_tab);
}