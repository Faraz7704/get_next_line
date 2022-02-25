# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 18:06:55 by faraz             #+#    #+#              #
#    Updated: 2022/02/25 16:13:55 by fkhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB		= ar -rcs
RM		= rm -f

SRCS	= get_next_line.c get_next_line_utils.c

BONUS_SRCS	= get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS	= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

bonus:		$(BONUS_OBJS)
			$(LIB) $(NAME) $(BONUS_OBJS)

%.o : %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
