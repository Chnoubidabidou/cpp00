NAME =	phonebook
SRC =	
OBJ = $(SRC:.cpp=.o)

C++ =  c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(C++_FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re bonus