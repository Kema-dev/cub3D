# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 12:13:37 by jjourdan          #+#    #+#              #
#    Updated: 2021/01/26 14:31:59 by jjourdan         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# *******************************    POST-IT    ****************************** #
#                                                                              #
#			## $@ 	Le nom de la cible										   #
#			## $< 	Le nom de la première dépendance						   #
#			## $^ 	La liste des dépendances								   #
#			## $? 	La liste des dépendances plus récentes que la cible		   #
#			## $* 	Le nom du fichier sans suffixe							   #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

DEBUG_FLAGS	=	-Wall -Wextra -fsanitize=address

RM			=	rm -f

NAME		=	Cub3D

MAKE_SUB	=	make -C libs/

DEBUG_OUT	=	debug.out

DEBUG_DIR	=	sources/debug_files/

DEBUG_FILES	=	debug_main.o

DEBUG_FULL	=	$(addprefix $(DEBUG_DIR), $(DEBUG_FILES))

INC_DIR		=	includes/

SRCS_DIR	=	sources/

SRCS		=	main.c

SRCS_FULL	=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS		=	$(SRCS_FULL:.c=.o)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
MLX_VAR		=	tux/
MLX_LIB		=	libmlx.a
LIBS		=	-L . -l mlx -L /usr/lib -lXext -lX11 -lm -lz libs/gnl/libgnl.a libs/libft/libft.a
O_TO_C		=	$(CC) $(FLAGS) -I/usr/include -I libs/mlx/tux -O3 -c $< -o $@
endif

ifeq ($(UNAME_S),Darwin)
MLX_VAR		=	mms/
MLX_LIB		=	libmlx.dylib
LIBS		=	-L . -l mlx -framework OpenGL -framework AppKit libs/gnl/libgnl.a libs/libft/libft.a
O_TO_C		=	$(CC) $(FLAGS) -I libs/mlx/mms/ -I $(INC_DIR) -c $< -o $@
endif

all:			libft gnl mlx $(NAME)

$(NAME): $(OBJS)
				$(CC) $(LIBS) $(OBJS) -o $(NAME)

%.o: %.c
				$(O_TO_C)

libft:
				$(MAKE_SUB)libft/

gnl:
				$(MAKE_SUB)gnl/

mlx:
				$(MAKE_SUB)mlx/$(MLX_VAR)
				mv libs/mlx/$(MLX_VAR)/$(MLX_LIB) ./$(MLX_LIB)

norme:			fclean
				printf "\033c"
				norminette libs/gnl/
				norminette libs/libft/
				norminette sources/

debug:			libft gnl mlx $(DEBUG_FULL) $(OBJS)
				$(CC) $(DEBUG_FLAGS) -I libs/mlx/mms/ -I $(INC_DIR) $(LIBS) $(filter-out sources/main.o, $(OBJS)) $(DEBUG_FULL) -o $(DEBUG_OUT)
				./$(DEBUG_OUT)

clean:
				$(RM) $(OBJS)
				$(RM) $(DEBUG_FULL)
				$(MAKE_SUB)libft/ clean
				$(MAKE_SUB)gnl/ clean
				$(MAKE_SUB)mlx/mms/ clean

fclean:
				$(RM) $(OBJS)
				$(RM) $(NAME)
				$(RM) $(DEBUG_FULL)
				$(RM) $(DEBUG_OUT)
				$(RM) $(MLX_LIB)
				$(MAKE_SUB)libft/ fclean
				$(MAKE_SUB)gnl/ fclean
				$(MAKE_SUB)mlx/mms/ clean

re:				fclean all

.PHONY: all, libft, gnl, mlx, norme, debug, clean, fclean, re
