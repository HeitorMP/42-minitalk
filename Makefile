# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmaciel- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 10:20:50 by hmaciel-          #+#    #+#              #
#    Updated: 2022/12/07 14:31:33 by hmaciel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Programs Name
CLIENT	=	client
SERVER	=	server

#libft Variables
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

#Sources Variables
SRC_C		=	client.c
SRC_S		=	server.c
INCLUDES	=	-I. -I$(LIBFT_DIR)

#Compilation
CC			=	cc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -f

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): $(LIBFT)
	@ $(CC) $(CFLAG) $(SRC_S) $(LIBFT) $(INCLUDES) -o $(SERVER)

$(CLIENT): $(LIBFT)
	@ $(CC) $(CFLAG) $(SRC_C) $(LIBFT) $(INCLUDES) -o $(CLIENT)


$(LIBFT):
	@ $(MAKE) -C ./libft

clean:
	@ $(RM) $(CLIENT) $(SERVER)

fclean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(CLIENT) $(SERVER)

re: fclean all

mandatory:	$(CLIENT) $(SERVER)
bonus:		mandatory

m : mandatory
b : bonus

.PHONY: all clean fclean re mandatory m bonus b
