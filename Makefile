# Project Name
NAME = pipex

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Paths
SRC_DIR = sources/
OBJ_DIR = obj/
INC_DIR = inc/
LIB_DIR = lib/
LIBFT_DIR = $(LIB_DIR)libft/
PRINTF_DIR = $(LIB_DIR)ft_printf/
INCLUDES = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)

# Libraries
LIBFT = $(LIBFT_DIR)libft.a
PRINTF = $(PRINTF_DIR)libftprintf.a

# Source Files
SRC =	pipex.c \
		ft_init_pipex.c \
		ft_check_args.c \
		ft_cleanup.c \
		ft_exec.c \
		ft_parse_args.c \
		ft_parse_cmds.c

# Add paths to source files
SRCS = $(addprefix $(SRC_DIR), $(SRC))

# Object Files
OBJ = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Default Target
all: $(NAME)

# Build Executable
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@echo "Linking $(NAME) with libraries..."
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

# Compile .o Files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build Libft
$(LIBFT):
	@echo "Building libft..."
	make -C $(LIBFT_DIR)

# Build ft_printf
$(PRINTF):
	@echo "Building ft_printf..."
	make -C $(PRINTF_DIR)

# Clean Object Files
clean:
	@echo "Cleaning object files..."
	$(RM) -r $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

# Full Clean (Object Files and Executable)
fclean: clean
	@echo "Removing $(NAME)..."
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

# Rebuild Everything
re: fclean all

# Memory Leak Check (valgrind)
leak: re
	valgrind --leak-check=full ./$(NAME)

# Debugging with gdb
debug: re
	gdb ./$(NAME)

# Phony Targets
.PHONY: all clean fclean re leak debug
