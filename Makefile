NAME			= push_swap

NAME_BONUS		= checker

CC				= cc
CFLAG			= -Wall -Wextra -Werror
RM				= rm -rf

SRC				= main.c ./parsing_and_control/parsing.c ./parsing_and_control/control.c \
					./algoritma/algoritma.c ./algoritma/algoritma_utils.c ./algoritma/sort_small.c \
					./min_move/min_move_cal.c ./min_move/min_move.c ./min_move/min_utils.c \
					./move/push.c ./move/reverse_rotate.c ./move/rotate.c  ./move/swap.c \
					./utils/utils.c ./utils/utils2.c ./utils/utils3.c ./utils/utils4.c \
					./utils/utils5.c ./utils/utils6.c

SRC_BONUS		= checker.c ./parsing_and_control/parsing.c ./parsing_and_control/control.c \
					./algoritma/algoritma.c ./algoritma/algoritma_utils.c ./algoritma/sort_small.c \
					./min_move/min_move_cal.c ./min_move/min_move.c ./min_move/min_utils.c \
					./move/push.c ./move/reverse_rotate.c ./move/rotate.c  ./move/swap.c \
					./utils/utils.c ./utils/utils2.c ./utils/utils3.c ./utils/utils4.c \
					./utils/utils5.c ./utils/utils6.c

OBJS			= $(SRC:.c=.o)

OBJS_BONUS		= $(SRC_BONUS:.c=.o)

${NAME}:	$(OBJS)

			@$(CC) $(CFLAG) $(SRC) -o $(NAME)


${NAME_BONUS}:	$(OBJS_BONUS)
				@$(CC) $(CFLAG) $(SRC_BONUS) -o $(NAME_BONUS)

%.o: %.c
	${CC} -c $< -o ${<:.c=.o}

clean:		
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME) $(NAME_BONUS) $(OBJS) $(OBJS_BONUS)

re:			fclean all

re_bonus: fclean all_bonus

bonus: ${NAME_BONUS}

all: 		${NAME}

all_bonus:	${NAME_BONUS}

.PHONY:		all all_bonus clean fclean re re_bonus

