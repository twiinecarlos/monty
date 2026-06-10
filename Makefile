CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
NAME = monty

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) *.c -o $(NAME)

clean:
	rm -f $(NAME)
