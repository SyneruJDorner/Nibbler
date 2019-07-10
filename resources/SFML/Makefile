NAME = libSnakeSFML.so

SRC = SnakeSFML.cpp
SRC2 =  testmain.cpp
CC = g++ -Wall -Wextra -Werror -std=c++11

FLAGS =  -Llib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: $(NAME)

$(NAME): fclean
	@  $(CC) -o snake $(SRC2)  -I include $(FLAGS)
	@ # $(CC) -shared -fPIC -o $(NAME) $(SRC) -I ../ -I SFML/include $(FLAGS)

clean:
	@rm -fr $(NAME)

fclean : clean

re: fclean all