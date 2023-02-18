# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 10:20:50 by hmaciel-          #+#    #+#              #
#    Updated: 2023/02/18 22:16:14 by hmaciel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Programs Name
CLIENT	=	client
SERVER	=	server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

#libft Variables
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

#Sources Variables
SRC_C		=	client.c
SRC_S		=	server.c
SRC_C_BONUS =	client_bonus.c
SRC_S_BONUS =	server_bonus.c
INCLUDES	=	-I. -I$(LIBFT_DIR)

#Compilation
CC			=	cc
CFLAG		=	-Wall -Wextra -Werror -g
RM			=	rm -f

all: $(SERVER) $(CLIENT)
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(NAME): all

$(SERVER): $(LIBFT)
	@ $(CC) $(CFLAG) $(SRC_S) $(LIBFT) $(INCLUDES) -o $(SERVER)

$(CLIENT): $(LIBFT)
	@ $(CC) $(CFLAG) $(SRC_C) $(LIBFT) $(INCLUDES) -o $(CLIENT)

$(BONUS): bonus

$(SERVER_BONUS): $(LIBFT)
	@ $(CC) $(CFLAG) $(SRC_S_BONUS) $(LIBFT) $(INCLUDES) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(LIBFT)
	@ $(CC) $(CFLAG) $(SRC_C_BONUS) $(LIBFT) $(INCLUDES) -o $(CLIENT_BONUS)

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR)

clean:
	@ $(RM) $(CLIENT) $(SERVER)
	@ $(RM) $(CLIENT_BONUS) $(SERVER_BONUS)
	@ $(MAKE) clean -C $(LIBFT_DIR)


fclean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re mandatory m bonus b
