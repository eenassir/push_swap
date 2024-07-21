NAME = push_swap

SRC = ft_strlen.c push_swap.c ft_atoi.c ft_split.c ft_exit.c ft_putstr.c ft_lstsize.c algo.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = #-fsanitize=address -g

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: clean