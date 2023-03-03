NAME			= push_swap

CC				= cc
CFLAG			= -Wall -Wextra -Werror
RM				= rm -rf

SRC				= main.c parsing.c control.c \
					./algoritma/algoritma.c ./algoritma/algoritma_utils.c \
					./min_move/min_move_cal.c ./min_move/min_move.c ./min_move/min_utils.c \
					./move/push.c ./move/reverse_rotate.c ./move/rotate.c  ./move/swap.c \
					./utils/utils.c ./utils/utils2.c ./utils/utils3.c ./utils/utils4.c \
					./utils/utils5.c ./utils/utils6.c
OBJS			= $(SRC:.c=.o)

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}:	$(OBJS)

			@$(CC) $(CFLAG) $(INC) $(SRC) -o $(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) $(OBJS)

re:			fclean all

all: 		${NAME}

.PHONY:		all clean fclean re

