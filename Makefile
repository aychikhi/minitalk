CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./utils/ft_atoi.c ./utils/ft_putchar.c ./utils/ft_putstr.c ./utils/ft_putendl.c ./utils/ft_putnbr.c\

OBJS = $(SRCS:.c=.o)

all: client server

client: ./mandatory/client.o $(OBJS) minitalk.h
	$(CC) $(CFLAGS) $(OBJS) ./mandatory/client.o -o client

server: ./mandatory/server.o $(OBJS) minitalk.h
	$(CC) $(CFLAGS) $(OBJS) ./mandatory/server.o -o server

bonus: client_bonus server_bonus

client_bonus: ./bonus/client_bonus.o $(OBJS) minitalk.h
	$(CC) $(CFLAGS) $(OBJS) ./bonus/client_bonus.o -o client_bonus

server_bonus: ./bonus/server_bonus.o $(OBJS) minitalk.h
	$(CC) $(CFLAGS) $(OBJS) ./bonus/server_bonus.o -o server_bonus

clean:
	rm -rf $(OBJS) ./mandatory/client.o ./mandatory/server.o ./bonus/client_bonus.o ./bonus/server_bonus.o

fclean: clean
	rm -rf client server client_bonus server_bonus

re: fclean all

.PHONY: clean