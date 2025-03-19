NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
FILES = extra_utils.c  ft_printf.c  handle_char.c  handle_decimale.c  handle_hexadecimale.c  handle_pointer.c  handle_string.c

OBJ =${FILES:%.c=%.o}

all: ${NAME}

$(NAME):${OBJ}
	$(AR) $@ $^

clean: 
	rm -f ${OBJ}

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY     : clean re all fclean bonus