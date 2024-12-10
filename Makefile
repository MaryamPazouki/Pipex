# Project Name
NAME = pipex

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Paths
SRC_DIR = sources/
OBJ_DIR = obj/
INCLUDES = -I inc/

# Source Files
SRC =	$(SRC_DIR)main.c \
		$(SRC_DIR)ft_init_pipex.c\
		$(SRC_DIR)ft_check_args.c\
		$(SRC_DIR)ft_cleanup.c \

# Object Files
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Default Target
all: $(NAME)

# Build Executable
$(NAME): $(OBJ)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Compile .o Files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean Object Files
clean:
	@echo "Cleaning object files..."
	$(RM) -r $(OBJ_DIR)

# Full Clean (Object Files and Executable)
fclean: clean
	@echo "Removing $(NAME)..."
	$(RM) $(NAME)

# Rebuild Everything
re: fclean all

leak: re
	valgrind --leak-check=full ./pipex

# Phony Targets
.PHONY: all clean fclean re