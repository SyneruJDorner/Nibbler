FLAGS = -Wall -Werror -Wextra -g -ofast
SRC = $(shell find . -name *.cpp)
OBJ_DIR = ./obj/
OBJ := $(SRC:%.cpp=$(OBJ_DIR)%.o)
EXEPATH = ./Compiled_Application/
EXECUTE = $(EXEPATH)Bureaucrat

GLFW3 = -I./resources/source/GLFW/include `pkg-config --cflags glfw3`  `pkg-config --static --libs glfw3`
SFML = -F./resources/source/SFML/Frameworks -framework SFML

SFML2 = -L./resources/build/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

SFMLLIBS = -L./resources/build/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SFML_INCLUDES = ./resources/source/SFML/include
SFML_DEPS = sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib;sfml-network-d.lib;sfml-audio-d.lib



CINDER = -L./resources/source/CINDER/include

all: $(EXECUTE)

$(EXECUTE): $(OBJ)
	@mkdir -p '$(@D)'
	@echo "COMPILING SOURCE $< INTO OBJECT $@"
	clang++ -std=c++11 $(FLAGS) -o $@ $^ $(CINDER)

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p '$(@D)'
	clang++ -std=c++11 $(FLAGS) -c -o $@ $<

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(EXEPATH)