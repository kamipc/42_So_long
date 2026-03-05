# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 14:55:59 by cpinho-c          #+#    #+#              #
#    Updated: 2026/03/05 23:18:58 by cpinho-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = so_long.c \
	   utils/checks.c \
	   utils/errors.c \
	   utils/map_checks.c \
	   utils/inits.c \
	   utils/map_ff_check.c \
	   utils/hooks.c \
	   utils/render.c

OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_GIT = https://github.com/kamipc/42_Libft.git
MINILIB_DIR = ./minilibx-linux
MINILIB = $(MINILIB_DIR)/libmlx.a
MINILIB_GIT = https://github.com/42paris/minilibx-linux.git
LIBS = -Lminilibx-linux -lmlx -lX11 -lXext
INCLUDES = -Iminilibx-linux

.Silent:

all: $(NAME)

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
	echo "Cloning libft..."; \
	git clone $(LIBFT_GIT) $(LIBFT_DIR); \
	fi
	$(MAKE) -C $(LIBFT_DIR)
	echo "Libft compiled successfully!"

$(MINILIB):
	@if [ ! -d "$(MINILIB_DIR)" ]; then \
	echo "Cloning libft..."; \
	git clone $(MINILIB_GIT) $(MINILIB_DIR); \
	fi
	$(MAKE) -C $(MINILIB_DIR)
	echo "Minilibx compiled successfully!"

$(NAME): $(LIBFT) $(MINILIB) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) $(LIBS)
	echo "$(NAME) compiled successfuly!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -C $(LIBFT_DIR) clean; fi

fclean: clean
	$(RM) $(NAME)
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -C $(LIBFT_DIR) fclean; fi

re: fclean all