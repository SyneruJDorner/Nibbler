NAME = libSnakeSFML.so

SRC = SnakeSFML.cpp
SRC2 =  testmain.cpp
CC = g++ -Wall -Wextra -Werror -std=c++11

FLAGS =  -L./lib/ -lglfw -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

all: $(NAME)
#compile GLAD



$(NAME): fclean
	@  gcc -c ./glad/src/glad.c -Wall -Wextra -Werror -I ./glad/include
	@  $(CC) -o snake $(SRC2)  -I include $(FLAGS) glad.o  -I ./glad/include


clean:
	@rm -fr $(NAME)

fclean : clean

re: fclean all
