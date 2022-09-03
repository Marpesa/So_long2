# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmery <lmery@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 12:12:58 by lmery             #+#    #+#              #
#    Updated: 2022/08/14 15:43:26 by lmery            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m
_PURPLE		=	\e[35m
_CYAN		=	\e[36m
_WHITE		=	\e[37m
_END		=	\e[0m
_BOLD		=	\e[1m



#Files

SRCS_DIR		= ./srcs/

FILES = main.c \
		check_map.c \
		check_walls.c \
		mandatory_chars.c \
		check_file_type.c \
		ft_final_free.c \
		init_map.c \
		events.c \
		ft_get_positions.c \
		move_heroe.c \
		collect_to_win.c \
		utils.c \
		draw_utils.c \
				

LIBFT		=	./Libft/libft.a
LIBFT_DIR	=	./Libft


LIB			=	make -C Libft

#----------------------Sources and objects-------------------

SRCS = $(addprefix $(SRCS_DIR), $(FILES))
SRCS_CHECKER = $(addprefix $(SRCS_DIR), $(FILES_CHECKER))

OBJS	=	$(SRCS:.c=.o)
OBJS_CHECKER	=	$(SRCS_CHECKER:.c=.o)


#----------------------- Constant strings --------------------

COMPILER		=	cc

FLAGS			=	-Wall -Wextra -Werror -g3

LD_FLAGS        =   -L mlx

MLX_FLAGS       =   -lm -lmlx -lXext -lX11

HEAD            =   -I includes -I mlx

INCLUDE			=	-I include

NAME			=	so_long

#----------------- Messages -----------------

SOLONG_READY	=	echo "$(_GREEN)$(_BOLD)\nGame ready !\n $(_YELLOW)Enter './so_long' and a valid map file to play$(_END)"

CLEANED			=	echo "$(_PURPLE)\nclean: All objects files removed\n$(_END)"

FCLEANED		=	echo "$(_PURPLE)\nfclean: Removed the executables and the objects files\n$(_END)"

TEXT			=	echo "$(_BLUE)\n\n 🐄 Help Moomoo the cow escape the planet. \n \
					🛸 Eat all the glowing flowers so the aliens let you come aboard. \n \
					💀 Beware of the farmers, they want to eat you. Unless... 🌻\n$(_END)"

#------------------------- Rules ---------------

all: $(NAME)

bonus: 

$(NAME): comp_libft comp_solong

comp_libft:
	@$(LIB)

comp_solong: $(OBJS)
	make -C mlx
	@$(COMPILER) $(FLAGS) $(LD_FLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MLX_FLAGS)
	@$(TEXT)
	@$(SOLONG_READY)

clean:
	@rm -rf $(OBJS)
	@make fclean -C Libft
	@$(CLEANED)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C Libft
	@$(FCLEANED)

.c.o:
	@${COMPILER} ${FLAGS} $(INCLUDE) -I so_long.h $(HEAD) -c $< -o ${<:.c=.o}

re: fclean all

.PHONY: all clean fclean re libft