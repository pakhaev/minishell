# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cimyan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 18:23:20 by cimyan            #+#    #+#              #
#    Updated: 2021/01/29 18:23:23 by cimyan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	minishell
FLAGS =	-Werror -Wextra -Wall
HEAD =	includes/minishell.h

SRCS =	sources/main/main.c \
		sources/main/ft_init.c \
		sources/builtin/ft_built_extra.c \
		sources/builtin/ft_cepe.c \
		sources/builtin/ft_eue.c \
		sources/env/ft_env.c \
		sources/env/ft_extended.c \
		sources/env/ft_get.c \
		sources/errors/ft_errors.c \
		sources/errors/ft_quit.c \
		sources/errors/ft_remove.c \
		sources/execute/ft_exec.c \
		sources/extra/ft_extra.c \
		sources/extra/ft_parser.c \
		sources/msg/ft_chevron.c \
		sources/msg/ft_msg.c \
		sources/msg/ft_parse_msg.c \
		sources/msg/ft_parse_msg_ext.c \
		sources/parse/ft_check.c \
		sources/parse/ft_parser.c \
		sources/parse/ft_reparser.c \
		sources/path/ft_dir.c \
		sources/path/ft_get.c \
		sources/path/ft_inout.c \
		sources/path/ft_path.c \
		sources/signal/ft_signal.c \
		sources/swars/ft_replace.c \
		sources/swars/ft_swars.c \
		sources/swars/ft_utils.c \


OBJS =	$(SRCS:.c=.o)

LIBFT =	libs/libft/libft.a
GNL = libs/gnl/*.c

RM = rm -f

$(NAME): $(OBJS) $(HEAD) $(LIBFT)
	gcc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(GNL)

$(LIBFT):
	@$(MAKE) -C libs/libft
	@make bonus -C libs/libft

$(OBJS): %.o:%.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@

all:	$(NAME)

clean:
		$(RM) $(OBJS)
		@make clean -C libs/libft

fclean:	clean
		$(RM) $(NAME)
		@make fclean -C libs/libft
		$(RM) *.out

re:		fclean all

.PHONY:		all clean fclean re
