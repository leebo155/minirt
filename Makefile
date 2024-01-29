CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -Iinclude -Isrc/libft/include -Isrc/ft_printf/include -Isrc/get_next_line/include -Ilib/minilibx
NAME = miniRT
SRCS = src/main/main.c \
	   src/valid/check_element.c \
	   src/valid/check_element_cylinder.c \
	   src/valid/check_string.c \
	   src/valid/my_atod.c \
	   src/valid/validation.c \
	   src/valid/print_error.c \
	   src/vector/constructor.c \
	   src/vector/multiply_divide.c \
	   src/vector/plus_minus.c \
	   src/vector/unit_minimum.c \
	   src/scene/double_vector.c \
	   src/scene/input_elements.c \
	   src/scene/obj_create.c \
	   src/scene/obj_list_utils.c \
	   src/scene/scene_init.c \
	   src/scene/shape_create.c \
	   src/trace/ray.c \
	   src/trace/hit.c \
	   src/trace/hit_sphere.c \
	   src/trace/hit_plane.c \
	   src/trace/hit_cylinder.c \
	   src/trace/light.c \
	   src/paint/init_mlx_vars.c \
	   src/paint/painting.c
LIBS = -Llib -lft -lgnl -Llib/minilibx -lmlx -framework OpenGL -framework Appkit
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(MAKE) -C src/libft clean
	$(MAKE) -C src/get_next_line clean
	$(MAKE) -C lib/minilibx clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C src/libft fclean
	$(MAKE) -C src/get_next_line fclean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

$(NAME): $(OBJS) lib/libft.a lib/libgnl.a lib/minilibx/libmlx.a
	$(CC) $(CFLAGS) $(LIBS) $(INC) -o $@ $(OBJS)

lib/libft.a:
	$(MAKE) -C src/libft all

lib/libgnl.a:
	$(MAKE) -C src/get_next_line all

lib/minilibx/libmlx.a:
	$(MAKE) -C lib/minilibx all

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $^
