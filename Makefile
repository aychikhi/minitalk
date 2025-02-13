CC = cc
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = ./utils/ft_atoi.c ./utils/ft_putchar.c ./utils/ft_putstr.c ./utils/ft_putendl.c ./utils/ft_putnbr.c\

OBJS = $(SRCS:.c=.o)

all: client server

client: client.o $(OBJS) minitalk.h
	$(CC) $(CFLAGS) $(OBJS) client.o -o client

server: server.o $(OBJS) minitalk.h
	$(CC) $(CFLAGS) $(OBJS) server.o -o server

clean:
	rm -rf $(OBJS) client.o server.o

fclean: clean
	rm -rf client server

re: fclean all

.PHONY: clean