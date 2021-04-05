NAME = libasm.a

TEST = test

NA = nasm
NA_FLAGS = -f macho64

SRCS = ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s

OBJS = $(SRCS:.s=.o)

%.o: %.s
	$(NA) $(NA_FLAGS) $<

.PHONY:	all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

test: re
	gcc main.c $(NAME) -o $(TEST)
	./$(TEST)
