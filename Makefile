# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/27 10:46:12 by jjourdan          #+#    #+#              #
#    Updated: 2021/01/27 14:03:05 by jjourdan         ###   ########lyon.fr    #
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

INC_DIR		=	includes/

SRCS_DIR	=	sources/

SRCS		=	ft_cub3d_main.c \
				ft_cub3d_get_color_info.c \
				ft_cub3d_shading_utils.c \
				ft_cub3d_pixel_manipulation.c \
				ft_cub3d_key_events_manager.c \
				ft_cub3d_exit_process.c

SRCS_FULL	=	$(addprefix $(SRCS_DIR), $(SRCS))

DEBUG_OUT	=	debug.out

DEBUG_DIR	=	sources/debug_files/

DEBUG_FILES	=	ft_cub3d_debug_main.o \

DEBUG_FULL	=	$(addprefix $(DEBUG_DIR), $(DEBUG_FILES))

OBJS		=	$(SRCS_FULL:.c=.o)

LIBS		=	-L . -l mlx -framework OpenGL -framework AppKit libs/gnl/libgnl.a libs/libft/libft.a

all:			libft gnl mlx $(NAME)

%.o: %.c
				$(CC) $(FLAGS) -I libs/mlx/mms/ -I $(INC_DIR) -c $< -o $@

$(NAME): $(OBJS)
				$(CC) $(LIBS) $(OBJS) -o $(NAME)

libft:
				$(MAKE_SUB)libft/

gnl:
				$(MAKE_SUB)gnl/

mlx:
				$(MAKE_SUB)mlx/mms/
				mv libs/mlx/mms/libmlx.dylib ./libmlx.dylib

norme:			fclean
				printf "\033c"
				norminette includes/
				norminette libs/gnl/
				norminette libs/libft/
				norminette sources/

debug:			libft gnl mlx $(DEBUG_FULL) $(OBJS)
				$(CC) $(DEBUG_FLAGS) -I libs/mlx/mms/ -I $(INC_DIR) $(LIBS) $(filter-out sources/ft_cub3d_main.o, $(OBJS)) $(DEBUG_FULL) -o $(DEBUG_OUT)
				./$(DEBUG_OUT)

cdebug:			libft gnl mlx $(DEBUG_FULL) $(OBJS)
				$(CC) $(DEBUG_FLAGS) -I libs/mlx/mms/ -I $(INC_DIR) $(LIBS) $(filter-out sources/ft_cub3d_main.o, $(OBJS)) $(DEBUG_FULL) -o $(DEBUG_OUT)
				printf "\033c"
				@./$(DEBUG_OUT)

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
				$(RM) libmlx.dylib
				$(MAKE_SUB)libft/ fclean
				$(MAKE_SUB)gnl/ fclean
				$(MAKE_SUB)mlx/mms/ clean

re:				fclean all

.PHONY: all, libft, gnl, mlx, norme, debug, clean, fclean, re
