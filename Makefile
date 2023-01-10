# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 10:54:47 by ichouare          #+#    #+#              #
#    Updated: 2023/01/10 12:11:49 by ichouare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker 
CC = cc 

FLAG = -Wall, -Wextra and -Werror 

HEADER = ./push_swap.h

SRCS = ./push_swap.c   ./extra_ft/ft_split.c  ./extra_ft/ft_calloc.c  ./extra_ft/ft_bzero.c  ./extra_ft/ft_atoi.c  ./actions/ra.c ./actions/sa.c ./actions/sb.c  ./actions/ss.c ./actions/rb.c ./actions/rr.c ./actions/rra.c ./actions/rrb.c ./actions/rrr.c actions/pa.c  ./actions/pb.c ./sort_small_stack.c  ./sort_medium_stack.c  ./sort_large_stack.c  ./sort_temp.c  ./extra_ft/ft_strjoin.c ./extra_ft/ft_strlen.c ./push_swap_utils.c

SRCSB = ./checker.c ./extra_ft/ft_split.c  ./extra_ft/ft_calloc.c  ./extra_ft/ft_bzero.c  ./extra_ft/ft_atoi.c  ./Bonusfcts2.c ./Bonusfcts1.c  ./sort_small_stack.c  ./sort_medium_stack.c  ./sort_large_stack.c  ./sort_temp.c  ./extra_ft/ft_strjoin.c ./extra_ft/ft_strlen.c ./extra_ft/ft_getnextLine.c  ./extra_ft/ft_getnextLine_util.c   ./extra_ft/ft_strcmp.c ./push_swap_utils.c
 
OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)


all: $(NAME)

Bonus :  $(NAME2)

$(NAME): $(OBJS) $(HEADER)
	$(CC)  $(FLAGS)  $(OBJS) -o $@
 
$(NAME2) :  $(OBJSB) $(HEADER)
	$(CC)  $(FLAGS)  $(OBJSB) -o $@
clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all 