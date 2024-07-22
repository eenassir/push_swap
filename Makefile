NAME = push_swap

SRC = ft_strlen.c push_swap.c ft_atoi.c ft_split.c ft_putstr.c ft_lstsize.c algo.c instructions_a.c instructions_b.c\
ft_lstaddback.c ft_lstaddfront.c ft_lstnew.c do_3_4_5.c algo_utils.c algo_utils2.c ft_free2.c ft_lst_free.c ft_strjoin.c

OBJ = $(SRC:.c=.o)

CC = gcc -g

CFLAGS = -Wall -Werror -Wextra

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