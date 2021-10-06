SRCS_NAME = printf.c \
	   printf_utils.c \
   	   printf_utils_two.c

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRCDIR = src

OBJDIR = obj

NAME = libftprintf.a

SRCS = $(addprefix $(SRCDIR)/, $(SRCS_NAME))

OBJS_NAME = $(SRCS_NAME:%.c=%.o)

OBJS = $(addprefix $(OBJDIR)/, $(OBJS_NAME))

.PHONY: all clean fclean re bonus

all: $(NAME)

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
		@$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJDIR):
		@mkdir -p $(OBJDIR) 2> /dev/null

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
