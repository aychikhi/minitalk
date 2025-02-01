NAME = minitalk
CC = cc
# CFLAGS = -Wall -Wextra -Werror 
# LDFLAGS = -fsanitize=address

SRCS = ./utils/ft_atoi.c

OBJS = $(SRCS:.c=.o)

all: server client

server: server.o $(OBJS)
	$(CC) $(CFLAGS) server.o $(OBJS) -o server 

client: client.o $(OBJS)
	$(CC) $(CFLAGS) client.o $(OBJS) -o client


clean:
	rm -f server.o client.o $(OBJS)

fclean: clean
	rm -rf server client

re: fclean all

.PHONY: clean