# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 12:13:37 by jjourdan          #+#    #+#              #
#    Updated: 2021/01/26 13:54:34 by jjourdan         ###   ########lyon.fr    #
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

DEBUG_FILES	=	main.c

INC_DIR		=	includes/

INC_FULL	=	$(addprefix $(INC_DIR), $(INCLUDES))

INCLUDES	=	cub3d.h

SRCS_DIR	=	sources/

SRCS		=	

SRCS_FULL	=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS		=	$(SRCS_FULL:.c=.o)

LIBS		=	-L libs/mlx/mlx_mms -l mlx -framework OpenGL -framework AppKit -L libs/gnl -l gnl -L libs/libft -l ft

all:			libft gnl mlx $(NAME)

$(NAME):		$(OBJS)
				$(CC) $(FLAGS) -I includes/ $(OBJS) $(LIBS) -o $(NAME)

libft:
				$(MAKE_SUB)libft/

gnl:
				$(MAKE_SUB)gnl/

mlx:
				$(MAKE_SUB)mlx/mlx_mms/

norme:
				norminette libs/gnl/
				norminette libs/libft/
				norminette sources/

debug:			all
				$(CC) $(DEBUG_FLAGS) -I includes/ $(LIBS) $(DEBUG_FILES) -o $(DEBUG_OUT)
				#printf "\033c"
				./$(DEBUG_OUT)

clean:
				$(RM) $(OBJS)
				$(MAKE_SUB)libft/ clean
				$(MAKE_SUB)gnl/ clean
				$(MAKE_SUB)mlx/mlx_mms/ clean

fclean:
				$(MAKE_SUB)libft/ fclean
				$(MAKE_SUB)gnl/ fclean
				$(MAKE_SUB)mlx/mlx_mms/ clean
				$(RM) $(NAME)
				$(RM) $(DEBUG_OUT)

re:				fclean all

.PHONY: all, libft, gnl, mlx, norme, debug, clean, fclean, re
