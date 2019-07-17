FLAGS = -Wall -Werror -Wextra
SRC = ./src/testmain2.cpp#$(shell find . -name *.cpp)
OBJ_DIR = ./obj/
OBJ := $(SRC:%.cpp=$(OBJ_DIR)%.o)
EXEPATH = ./Compiled_Application/
EXECUTE = $(EXEPATH)TEST

GLFW_FLAGS = -L./Libraries/ -I./resources/GLFW/glad/include/ -I./resources/GLFW/include 

all: $(EXECUTE)

$(EXECUTE): $(OBJ)
	. ./BuildLib.sh
	
	@ mkdir -p '$(@D)'

	@ echo "COMPILING SOURCE $< INTO OBJECT $@"
	@ clang++ $(FLAGS) -o $@ $^ $(GLFW_FLAGS)
	

$(OBJ_DIR)%.o: %.cpp
	@ mkdir -p '$(@D)'
	@ clang++ $(FLAGS) -I./resources/GLFW/glad/include/ -I./resources/GLFW/include -c -o $@ $<

fclean:
	@ rm -rf $(OBJ_DIR)
	@ rm -rf $(EXEPATH)
	@ rm -rf ./resources/GLFW
	@ rm -rf ./resources/SFML
	@ rm -rf ./resources/SDL2
	@ rm -rf ./Libraries
	. ./FCleanLib.sh