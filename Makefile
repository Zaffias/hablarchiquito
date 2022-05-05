# COLORS #
GREEN = @echo "\033[0;32m"
BLUE = @echo "\033[0;34m" 
PURPLE = @echo "\033[0;35m"
CYAN = @echo "\033[0;36m"
RESET = "\033[1;0m"

# VARIABLES #
NAME = Minitalk
SVR_NAME	= server
CLNT_NAME	= client
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-g3

# PATHs #
OBJ_PATH    = objects


# SOURCES #
SRC =   client.c\
        server.c

# RULES #
all: $(NAME)

OBJS_NAME = $(SRC:%.c=%.o)

#SRCS = $(addprefix $(SRC_PATH)/, $(SRC))


$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 2> /dev/null

$(OBJ_PATH)/%.o: $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@
            
$(NAME): $(OBJS)
	$(GREEN)CREANDO SERVIDOR Y CLIENTE $(RESET)
	$(CC) $(CFLAGS) server.c -o $(SVR_NAME) 
	$(CC) $(CFLAGS) client.c -o $(CLNT_NAME)
	

##RULES
$(MAKE): make


clean:
	rm -rf $(OBJS)
	
fclean: clean
	$(BLUE)MATANDO SERVER Y CLIENT $(RESET)
	rm -rf $(SVR_NAME)
	rm -rf $(CLNT_NAME)
	rm -rf $(OBJ_PATH)

re: fclean all

PHONY.: all clean fclean re norminette