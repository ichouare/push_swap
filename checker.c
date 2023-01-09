/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:39:50 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/09 20:34:20 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

void ft_pop(char **str, int **stack_a , int *top, int i)
{
    while(i >= 0)
    {
        *top = *top + 1;
        (*stack_a)[*top]  = ft_atoi(str[i]);
        i--;
    }
}
char **enter_function()
{
    char *buffer;
    buffer  = (char *)ft_calloc(1 , sizeof(char));
    char *str2;
    int sz;
    str2 = get_next_line(0);
    while(str2 != NULL)
    {
        if(ft_strcmp(str2 , "ra") != 0 && ft_strcmp(str2 , "pa") != 0  && ft_strcmp(str2 , "pb") != 0
           && ft_strcmp(str2 , "rb") != 0 && ft_strcmp(str2 , "rb") != 0 && ft_strcmp(str2 , "rra") != 0
            && ft_strcmp(str2 , "rrb") != 0 && ft_strcmp(str2 , "rrr") != 0  && ft_strcmp(str2 , "sa") != 0
            && ft_strcmp(str2 , "sb") != 0 && ft_strcmp(str2 , "ss") != 0)
        {
                write(1, "Error\n", 7);
                exit(1);
        }
        buffer = ft_strjoin(buffer, str2);
        buffer = ft_strjoin(buffer, " ");
        str2 = get_next_line(0);
        
    }
    return(ft_split(buffer , ' '));
}

void make_func(char **fcts , int *stack_a, int *stack_b, int top, int topb)
{
    int i;

    i = 0;
    while(fcts[i])
    {
        if(ft_strcmp(fcts[i] , "ra") == 0)
            ra(stack_a,top);
        else if (ft_strcmp(fcts[i] , "pa") == 0)
            pa(stack_a, stack_b, &top, &topb);
        else if(ft_strcmp(fcts[i] , "pb") == 0)
            pb(stack_a, stack_b, &top, &topb);
        else if(ft_strcmp(fcts[i] , "rb") == 0)
            rb(stack_b, topb);
        else if(ft_strcmp(fcts[i] , "ss") == 0)
            ss(stack_a,top,  stack_b,  topb);
        else if(ft_strcmp(fcts[i] , "rra") == 0)
            rra(stack_a, top);
        else if(ft_strcmp(fcts[i] , "rrb") == 0)
            rrb(stack_b, topb);
        else if(ft_strcmp(fcts[i] , "rrr") == 0)
            rrr(stack_a, top, stack_b, topb);
        else if(ft_strcmp(fcts[i] , "sa") == 0)
                sa(stack_a, top);
        else if(ft_strcmp(fcts[i] , "sb") == 0)
            sb(stack_b, topb);
        else
        {
            write(1, "Error\n", 7);
            exit(1);   
        }
    i++;
    }
}

int check_sort(int *stack_a,int top)
{
    int i;
    
    i = top;
    while(i > 0)
    {
        if(stack_a[i] > stack_a[i - 1])
            return(1);
        i--;
    }
    return(0);

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
    char **fcts;
    
    i = 0;
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
    i = 0;
    while(str[i])
    {
        j = 0;
        if(ft_strlen(str[i]) == 1)
        {
            if(str[i][0] < '0' || str[i][0] > '9' )
            {
                write(1,"Error : some arguments aren’t integers\n", 41);
                exit(0);
            }
        }
        else
        {
            if(str[i][0] != '-' && str[i][0] != '+' && (str[i][0] < 48 || str[i][0] > 57))
            {
                write(1,"Error : some arguments aren’t integers\n", 41);
                exit(0);
            }
            j = 1;
            while(str[i][j])
            {
                if(str[i][j] < '0' || str[i][j] > '9')
                {
                    write(1,"Error : some arguments aren’t integers\n",  41);
                    exit(0);
                }
                j++;
            }
        }
       
        i++;
    }
    stack_a = (int *) malloc( i *   sizeof(int));
    stack_b = (int *) malloc( i *   sizeof(int));
    i--;
    ft_pop(str, &stack_a, &top, i);
    if(check_arr(stack_a, top) == 0)
    {
        free(stack_a);
        free(stack_b);
        write(1,"Error :  some arguments are bigger than an integer and/or there are duplicates\n", 79);
        exit(0);
    }
    fcts = enter_function();
    make_func(fcts, stack_a,  stack_b, top, topb);
    if(check_sort(stack_a, top) == 1)
        write(1, "KO\n", 4);
    else
        write(1, "OK\n", 4);

    // i = top;
    // while( i >= 0)
    // {
    //     printf("|%d|\n", stack_a[i]);
    //     i--;
    // }
  

   
    return(0);
}