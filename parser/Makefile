# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 19:22:54 by ptungbun          #+#    #+#              #
#    Updated: 2023/07/11 19:22:56 by ptungbun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	minishell
LIBFT			=	libft/libft.a
libminishell	=	libminishell/minishell.a
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra

# Variable declaration of directory
INCS_DIR		= ./includes
BUILD_DIR		= ./build

# Variable declaration of file

SRCS			=	main.c prompt.c lexer.c grab.c init_command_list.c \
					quotes_validate.c tokenize.c paser.c contain_cmd_to_table.c \
					get_table.c

OBJS			=	$(SRCS:%.c=$(BUILD_DIR)/%.o)

# Variable declaration of linking lib

OPENDIR			=	-I./libft -I./includes -I./libminishell -L./usr/include/readline -L./libft -L./libminishell
LIBLINK			=	-lft -lminishell -lreadline

# Build step for C source
# gcc -I./includes -L./usr/include -I./libft -L./libft main.c prompt.c -lreadline -lft << compliable

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OPENDIR) $(OBJS) -o $(NAME) $(LIBLINK)

$(OBJS): $(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(OPENDIR) -c $< -o $@ $(LIBLINK)

$(LIBFT):
	make -C libft

$(LIBMINISHELL):
	make -C libminishell

clean:
	@rm -rf $(BUILD_DIR)

fclean:
	@rm -rf $(NAME) $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
