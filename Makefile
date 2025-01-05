NAME = libftprintf.a
AR = ar rcs
CC = cc
CFLAGS = -Werror -Wextra -Wall
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC = ft_printf.c ft_printf_utils.c
OBJ = ft_printf_utils.o ft_printf.o
INCLUDES = -I. -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT): 
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re