# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfourne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/31 14:07:32 by jfourne           #+#    #+#              #
#    Updated: 2017/03/22 13:10:09 by jfourne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all, clean, fclean, re

SRC_PATH	=	src

SRC_NAME	=	main.c \
				init_term_tty.c \
				key_binding.c \
				key_binding_second.c \
				key_binding_third.c \
				my_putc.c \
				reverse_video_underline.c \
				ft_select.c \
				signal.c \
				ft_print_frame.c \
				ft_print_choice.c \
				ft_print_with_color.c \

OBJ_PATH	=	obj

CPPFLAGS	=	-Iinclude

LDFLAGS		=	-Llibft

LDLIBS		=	-lft -ltermcap

NAME		=	ft_select

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra

OBJ_NAME	=	$(SRC_NAME:.c=.o)

SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all:			$(NAME)

$(NAME):		$(OBJ)
				@cd libft; make; cd ..
				@echo "libft created"
				@$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@
				@echo "compilation completed"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
				@cd libft; make clean; cd ..
				@rm -rf $(OBJ)
				@rm -rf $(OBJ_PATH)
				@echo "rm OBJ"

fclean:			clean
				@cd libft; make fclean; cd ..
				@rm -rf $(NAME)
				@echo "rm NAME"

re:				fclean all
				@cd libft; make re; cd ..
