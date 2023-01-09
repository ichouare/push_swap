/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:14:26 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/09 17:04:57 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  is_sorted(int *stack_a , int top)
{
    int i;
    int j;

    i = top;
    j = top;
    while(i > 0)
    {
        if(stack_a[j] < stack_a[j - 1])
            j--;   
        i--;
    }
    if(j == 0)
        exit (0);
}

int  check_arr(int *stack_a , int top)
{
    int i;
    int j;

    i = top;
   while(i >= 0)
   {
        j =  i - 1;
        while( j >= 0)
        {
            if(stack_a[i] == stack_a[j] || stack_a[i] > 2147483647 || stack_a[i] < -2147483647)
                return(0);
            j--;
        }
        i--;
   }
    return(1);
}
int check_stack(char **str)
{
    int i;
    int j;
     i = 0;
    while(str[i])
    {
        j = 0;
        if(ft_strlen(str[i]) == 1)
        {
            if(str[i][0] < '0' || str[i][0] > '9' )
            {
                write(1,"Error : some arguments aren't integers\n", 41);
                exit(0);
            }
        }
        else
        {
            if(str[i][0] != '-' && str[i][0] != '+' && (str[i][0] < 48 || str[i][0] > 57))
            {
                write(1,"Error : some arguments aren't integers\n", 41);
                exit(0);
            }
            j = 1;
            while(str[i][j])
            {
                if(str[i][j] < '0' || str[i][j] > '9')
                {
                    write(1,"Error : some arguments aren't integers\n",  41);
                    exit(0);
                }
                j++;
            }
        }
       
        i++;
    }
    return (i);
}
void ft_pop(char **str, int **stack_a , int *top, int i)
{
    int j;
    
    j = 0;
    while(i >= 0)
    {
        *top = *top + 1;
        (*stack_a)[*top]  = ft_atoi(str[i]);
        i--;
    }
}

int main(int argc , char **agrv)
{
    char **str;
    char *args;
    int   i;
    int *stack_a;
    int *stack_b;
    int top;
    int topb;
    int j;
    

    top = -1;
    topb =-1;
    if(argc == 1)
       {
         write(1, "no parameters are specified\n" ,29);
         exit(0);
       }
    i = 1;
    args = agrv[i];
    i = 2;
    while(i < argc)
    {
        char *tmp;
        tmp = args;
        args = ft_strjoin(args, " ");
        if(i!=2)
            free(tmp);
        tmp = args;
        args = ft_strjoin(args, agrv[i]);
        free(tmp);
        i+=1;
    }
    str = ft_split(args, ' ');
    i = check_stack(str);
    stack_a = (int *)malloc(i * sizeof(int));
    stack_b = (int *)malloc(i * sizeof(int));
    i--;
    ft_pop(str, &stack_a , &top, i);
    is_sorted(stack_a, top);
    i = top;
    if(check_arr(stack_a, top) == 0)
    {
        free(stack_a);
        free(stack_b);
        write(1,"Error :  some arguments are bigger than an integer and/or there are duplicates\n", 79);
         exit(0);
    }
    if(top == 2)
       sort_small_stack(stack_a , top);   
    else if(top == 4)
        sort_medium_stack(stack_a ,stack_b , &top , &topb);
    else
        sort_large_stack(stack_a , stack_b , &top  , &topb);
    i = top;
    free(stack_a);
    free(stack_b);
    return(0);
}