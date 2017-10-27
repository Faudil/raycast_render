##
## Makefile for Makefile in /home/faudil.puttilli/delivery/CPool_Day10/CPool_Day10/do-op
##
## Made by Faudil PUTTILLI
## Login   <faudil.puttilli@epitech.net>
##
## Started on  Sun Oct 16 19:25:02 2016 Faudil PUTTILLI
## Last update Wed Aug  2 15:42:09 2017 guacamole
##

CC			= 	gcc -Ofast

RM			= 	rm -f

CFLAGS	+=	-I./include -W -Wall -Wextra

CSFML	= -lc_graph_prog -lm

NAME    = 	wolf3d

SRCS    = 	main.c				\
		srcs/utils.c			\
		srcs/wolf3d.c			\
		srcs/my_draw_line.c		\
		srcs/event.c			\
		srcs/read_file.c		\
		srcs/raycasting.c		\
		srcs/print_framebuffer.c 	\
		srcs/draw_form.c		\
		srcs/map_handler.c		\
		srcs/mini_map.c			\
		srcs/event_env.c		\
		srcs/creator.c			\
		srcs/str.c

OBJS	=	$(SRCS:%.c=obj/%.o)

all: $(NAME)

obj/%.o: %.c
	@mkdir -p obj/srcs
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CSFML) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) -rf obj

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
