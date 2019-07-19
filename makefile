FLAGS = -Wall -Werror -Wextra
SRC = $(shell find ./src -name *.cpp)
OBJ_DIR = ./obj/
OBJ := $(SRC:%.cpp=$(OBJ_DIR)%.o)
EXEPATH = ./Executable/
EXECUTE = $(EXEPATH)TEST

GLFW_FLAGS = -L./libraries/ -I./resources/GLFW/glad/include/ -I./resources/GLFW/include 

all: build $(EXECUTE)


$(EXECUTE): $(OBJ)
	@ mkdir -p '$(@D)'

	@ echo "COMPILING SOURCE $< INTO OBJECT $@"
	@ clang++ $(FLAGS) -o $@ $^ $(GLFW_FLAGS)
	

$(OBJ_DIR)%.o: %.cpp
	@ mkdir -p '$(@D)'
	@ clang++ $(FLAGS) -I./resources/GLFW/glad/include/ -I./resources/GLFW/include -c -o $@ $<

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