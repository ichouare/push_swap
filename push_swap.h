/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:55:07 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/10 17:59:14 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h> 
# include <fcntl.h>

typedef struct list
{
	int	*a;
	int	*b;
	int	top;
	int	topb;
}	t_list;

typedef struct BonusList
{
	int		*a;
	int		*b;
	int		top;
	int		topb;
	char	**str;
	char	*args;
	char	**fcts;
}	t_Bonus;

void	*ft_calloc(size_t number, size_t size);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
void	sort_small_stack(int *a, int top);
int		sa(int *a, int top);
int		sb(int *b, int top);
int		ss(int *a, int topa, int *b, int topb);
int		ra(int *a, int topa);
int		rb(int *b, int topb);
void	rr(int *a, int topa, int *b, int topb);
int		rra(int *a, int top);
int		rrb(int *b, int top);	
int		rrr(int *a, int topa, int *b, int topb);
int		pa(int *a, int *b, int *topa, int *topb);
void	sort_medium_stack(int *a, int *b, int *top, int *topb);
int		pb(int *a, int *b, int *topa, int *topb);
void	sort_large_stack(t_list *tvars);
int		*sort_temp(int *tab, int top);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
size_t	found_nl(const char *str, int c);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(char *p1, char *p2);
void	ft_pop(char **str, int **stack_a, int *top, int i);
void	ft_free(int *stack_a, int *stack_b);
void	ft_error(char *str, int length);
void	is_sorted(int *stack_a, int top);
int		check_arr(int *stack_a, int top);
char	**check_parms(int argc, char **agrv);
#endif
