FLAGS = -Wall -Werror -Wextra -std=c++11
SRC = $(shell find ./src -name *.cpp)
OBJ_DIR = ./obj/
OBJ := $(SRC:%.cpp=$(OBJ_DIR)%.o)
EXEPATH = ./Executable/
EXECUTE = $(EXEPATH)Nibbler

GLFW_FLAGS = -L./libraries/ -I./resources/GLFW/glad/include/ -I./resources/GLFW/include 

SDL_INCLUDE = -I ./resources/SDL2/include
GLAD_INCLUDE = -I ./resources/GLFW/glad/include
GLFW_INCLUDE = -I ./resources/GLFW/include
SFML_INCLUDE = -I ./resources/SFML/include
ALL_INCLUDES = $(SDL_INCLUDE) $(GLAD_INCLUDE) $(GLFW_INCLUDE) $(SFML_INCLUDE)

all: build $(EXECUTE)


$(EXECUTE): $(OBJ)
	@ mkdir -p '$(@D)'

	@ echo "COMPILING SOURCE $< INTO OBJECT $@"
	@ clang++ $(FLAGS) -o $@ $^ $(GLFW_FLAGS)
	

$(OBJ_DIR)%.o: %.cpp
	@ mkdir -p '$(@D)'
	@ clang++ $(FLAGS) $(ALL_INCLUDES) -c -o $@ $<

build:
	. ./Setup.sh
	. ./BuildLib.sh

fclean:
	@ rm -rf $(OBJ_DIR)
	@ rm -rf $(EXEPATH)
	@ rm -rf ./resources/GLFW
	@ rm -rf ./resources/SFML
	@ rm -rf ./resources/SDL2
	@ rm -rf ./libraries
	. ./FCleanLib.sh