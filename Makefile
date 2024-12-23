NAME = libftprintf.a

AR = ar -rcvs
CC = cc
CFLAGS = -Werror -Wextra -Wall
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)/libft.a
SRC = ft_printf.c ft_printf_utils.c
OBJ = $(SRC:.c=.o)


all: $(LIBFT) $(NAME)

$(LIBFT): 
	make -C libft

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ) $(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) $(SRC) -o $@

clean : 
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

