NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./utils/ft_atoi.c ./utils/ft_putchar_fd.c ./utils/ft_putstr_fd.c ./utils/ft_putendl_fd.c\
		./utils/ft_putnbr_fd.c\

SRCS1 = ./mandatory/server.c
SRCS2 = ./mandatory/client.c
SRCSB1 = ./bonus/server_bonus.c
SRCSB2 = ./bonus/client_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

OBJSB1 = $(SRCSB1:.c=.o)
OBJSB2 = $(SRCSB2:.c=.o)

all: server client

server: $(OBJS1) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS1) $(OBJS) -o server 

client: $(OBJS2) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS2) $(OBJS) -o client

bonus: server_bonus client_bonus

server_bonus: $(OBJSB1) $(OBJS)
	$(CC) $(CFLAGS) $(OBJSB1) $(OBJS) -o server_bonus

client_bonus: $(OBJSB2) $(OBJS)
	$(CC) $(CFLAGS) $(OBJSB2) $(OBJS) -o client_bonus

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS1) $(OBJS2) $(OBJSB1) $(OBJSB2) $(OBJS)
fclean: clean
	rm -rf server client server_bonus client_bonus

re: fclean all

.PHONY: clean