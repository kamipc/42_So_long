# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpinho-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 14:55:59 by cpinho-c          #+#    #+#              #
#    Updated: 2025/05/18 14:56:01 by cpinho-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = so_long.c utils/checks.c utils/errors.c utils/map_checks.c \
	   utils/inits.c utils/map_ff_check.c utils/hooks.c utils/render.c
OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBFT = libft/libft.a
MINILIB = minilibx-linux/libmlx.a
LIBS = -Lminilibx-linux -lmlx -lX11 -lXext
INCLUDES = -Iminilibx-linux

.Silent:

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIB)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all