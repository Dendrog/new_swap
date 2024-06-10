NAME =          push_swap
BNAME =			checker

SRCS =  main.c\
		n_guard.c\
		stacks.c\
		utils.c\
		oper_swap.c\
		oper_push.c\
		oper_rotate.c\
		oper_reverse.c\
		sort.c\
		utils2.c\
		a_sort.c\
		b_sort.c\
		a_sort2.c\
		b_sort2.c
	
BONUS =		checker.c\
			n_guard.c\
			stacks.c\
			utils.c\
			oper_swap.c\
			oper_push.c\
			oper_rotate.c\
			oper_reverse.c\
			sort.c\
			utils2.c\
			a_sort.c\
			b_sort.c\
			a_sort2.c\
			b_sort2.c

LIB = libft/libft.a\
		ft_printf/libftprintf.a\
		get_next_line/gnl.a

HEADR = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
OBJS = $(SRCS:.c=.o)
BOBJS = $(BONUS:.c=.o)

ifdef BNS
OBJ = $(BOBJS)
NAME = $(BNAME)
else
OBJ = $(OBJS)
endif

all: $(LIB) $(NAME)

$(LIB):
	@make re -C ./libft
	@make re -C ./ft_printf
	@make re -C ./get_next_line

$(NAME): $(OBJ) $(HEADR)
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

bonus:
	@make BNS=1 all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ./libft
	@make clean -C ./ft_printf
	@make clean -C ./get_next_line
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BNAME)
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re bonus

