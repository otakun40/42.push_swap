NAME 			=	push_swap

NAME_BONUS		=	checker

HEADER 			=	push_swap.h

HEADER_BONUS	= 	checker.h

LIBFT 			=	./libft/libft.a

SRCS 			=	push_swap.c		stack_utils.c			sort_utils_1.c		sort_utils_2.c 			ft_printf.c		\
					parsing_tools.c exit_utils.c			stack_utils2.c		stack_params_utils.c	sort_utils_3.c	\
					check_utils.c	stack_params_utils_2.c	basic_utils.c		sort_utils_4.c

SRC_BONUS		=	checker_bonus.c 	get_next_line_bonus.c 	get_next_line_utils_bonus.c		ft_printf_bonus.c	\
					sort_utils_bonus.c	sort_utils_bonus_1.c	stack_utils_bonus.c				check_utils_bonus.c

OBJS			= 	${SRCS:.c=.o}

OBJS_BONUS		= 	${SRC_BONUS:.c=.o}

CC 				= 	gcc

CFLAGS 			= 	-Wall -Wextra -Werror

all				:	${NAME}

%.o 			:	%.c ${HEADER}
					${CC} ${CFLAGS} $< -c -o $@

%_bonus.o		:	%_bonus.c ${HEADER_BONUS}
					${CC} ${CFLAGS} $< -c -o $@

${NAME}			:	${OBJS} ${LIBFT}
					${CC} ${CFLAGS} ${OBJS}	-Llibft -lft -o ${NAME}

bonus		:		${NAME_BONUS}


${NAME_BONUS}	:	${OBJS_BONUS} ${LIBFT}
					${CC} ${CFLAGS} ${OBJS_BONUS} -Llibft -lft -o ${NAME_BONUS}
${LIBFT}		:	libft ;

libft			:
					${MAKE}	-C ./libft

clean			:
					rm -rf ${OBJS} ${OBJS_BONUS}
					${MAKE} -C ./libft clean

fclean			:
					rm -rf ${OBJS} ${OBJS_BONUS} ${NAME} ${NAME_BONUS}
					${MAKE} -C ./libft fclean

re				:	fclean ${NAME}

.PHONY			:	all re clean fclean debug debug_bonus ch_leak run libft
