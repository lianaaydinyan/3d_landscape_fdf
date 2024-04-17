NAME = fdf
CC = cc
CFLAGS =-Wall -Wextra -Werror 
SRC = $(wildcard  ./src/*.c)
OBJ = $(SRC:.c=.o)
LOBI = ./libb/libft.a
PRINT = ./ft_printf/libftprintf.a

all : lala lalala $(NAME)

lala :
	@make -C ./libb

lalala :
	@make -C ./ft_printf

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(LOBI) $(PRINT) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	@make -C ./libb clean
	@make -C ./ft_printf clean
	rm -rf $(OBJ)

fclean : clean
	@make -C ./libb fclean
	@make -C ./ft_printf fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all , re , clean, fclean