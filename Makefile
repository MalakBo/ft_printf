# Source files
SRC = ft_printf.c
# Object files 
OBJ = $(SRC:.c=.o)
NAME=printf.a
# The name of the library
CC = gcc
# Compiler and flags
CFLAGS = -Wall -Werror -Wextra
# Builds the library
all:$(NAME)
# Rule to create the library (NAME) from object files (OBJ)
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) 
# Bonus target: adds bonus object files (OBJB) to the library
bonus: $(OBJB)
	ar rcs $(NAME) $(OBJB)
# Compiles .c to .o with given flags
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# Removes all object files
clean:
	rm -rf $(OBJ) $(OBJB)
# Removes object files and the library file
fclean: clean
	rm -rf $(NAME)
# Rebuild target.
re: fclean all