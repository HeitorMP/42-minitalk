################################################################################
#                                     CONFIG                                   #
################################################################################

NAME			:= server
CLIENT			:= client
BONUS			:= server_bonus
BONUS_CLIENT	:= client_bonus
CC				:= cc
FLAGS			:= -Wall -Wextra -Werror
LIBFT			:=	./libft/libft.a
LIBFT_DIR		:=	./libft
RM				:= rm -f

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS_S			:= server.c
SRCS_C			:= client.c
BONUS_SRCS_S	:= server_bonus.c
BONUS_SRCS_C	:= client_bonus.c

OBJS_S			:= server.o
OBJS_C			:= client.o
BONUS_OBJS_S	:= server.o
BONUS_OBJS_C	:= client.o

################################################################################
#                                  Makefile  objs                              #
################################################################################

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

${NAME}:			${OBJS_S} ${CLIENT} ${LIBFT}
					@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW} $(NAME) ${CLR_RMV}..."
					${CC} ${FLAGS} -o ${NAME} ${OBJS_S} ${LIBFT}
					@echo "$(GREEN)$(NAME) created[0m ✔️"

${CLIENT}:			${OBJS_C} ${LIBFT}
					@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW} ${CLIENT} ${CLR_RMV}..."
					${CC} ${FLAGS} -o ${CLIENT} ${OBJS_C} ${LIBFT}
					@echo "$(GREEN)$(CLIENT) created[0m ✔️"

${BONUS}:			${BONUS_OBJS_S} ${BONUS_CLIENT} ${LIBFT}
					@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW} ${BONUS} ${CLR_RMV}..."
					${CC} ${FLAGS} -o ${BONUS} ${BONUS_OBJS_S} ${LIBFT}
					@echo "$(GREEN)$(BONUS) created[0m ✔️"

${BONUS_CLIENT}:	${BONUS_OBJS_C} ${LIBFT}
					@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW} ${BONUS_CLIENT} ${CLR_RMV}..."
					${CC} ${FLAGS} -o ${BONUS_CLIENT} ${BONUS_OBJS_C} ${LIBFT}
					@echo "$(GREEN) $(BONUS_CLIENT) created[0m ✔️"

${LIBFT}:
			@ $(MAKE) -C $(LIBFT_DIR)

all:		${NAME} ${CLIENT}

bonus:		${BONUS} ${BONUS_CLIENT}

clean:
			@ $(MAKE) clean -C $(LIBFT_DIR)
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ $(MAKE) fclean -C $(LIBFT_DIR)
			@ ${RM} ${NAME} ${CLIENT} ${BONUS} ${BONUS_CLIENT}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


