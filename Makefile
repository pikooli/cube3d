
SRC	= ft_annexe_getmap.c \
draw.c \
ft_check_map.c\
ft_get_map.c\
ft_map2map2_annexe.c\
ft_sprite.c\
put_image.c\
draw_minimap.c\
ft_check_map2.c\
ft_get_sprite.c\
ft_orientation.c\
get_next_line.c\
ray.c\
ft_annexe.c\
ft_detect.c\
ft_init.c\
ft_save_image.c\
key_hand.c\
ft_free.c \
ft_map2map2.c \
ft_split.c\
main.c\

SRCS 	= $(addprefix ./srcs/,$(SRC))

OBJS    = ${SRCS:.c=.o}

CC      = gcc

INC		= include

CFLAGS  = -Wall -Wextra -Werror -I $(INC)

NAME	= Cub3D

MLX		=  -lmlx -framework OpenGL   -framework AppKit 

.c.o	: ${CC} $(MLX)  ${CFLAGS} -c $< -o ${<:.c=.o}

all		:	$(OBJS) 
			gcc $(MLX) $(OBJS) -o $(NAME)

clean 		:	
				rm -f ${NAME}

re 			:   fclean all

.PHONY		:	all clean fclean re

