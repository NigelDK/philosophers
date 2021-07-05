NAME = philo

SRC_DIR = srcs

SRC =	main.c \
		init_struct.c \
		ft_atol.c \
		philo_actions.c \
		timestamp.c \
		free_all.c \
		put_msg.c \

OBJ_DIR = objs

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

HEADER_FOLDER = includes

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I${HEADER_FOLDER} -pthread -g

RM = rm -rf


all:	$(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME):	$(OBJ_DIR) $(OBJ)
	@echo "Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(HEADER)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files"
	@$(RM) $(OBJ) $(OBJ_DIR)

fclean:
	@echo "Removing object files"
	@$(RM) $(NAME) $(OBJ) $(OBJ_DIR)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
