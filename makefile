FLAGS = -Wall -Werror -Wextra
SRC = ./src/testmain.cpp#$(shell find . -name *.cpp)
OBJ_DIR = ./obj/
OBJ := $(SRC:%.cpp=$(OBJ_DIR)%.o)
EXEPATH = ./Compiled_Application/
EXECUTE = $(EXEPATH)SNAKE

GLAD_INCLUDE = -I./resources/GLFW/glad/include

GFLW_FLAGS = -I./resources/GLFW/include -L./resources/GLFW/lib/ -lglfw -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
SFML_FLAGS = -I./resources/SFML/include -L./resources/SFML/lib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SDL_FLAGS = -I./resources/SDL2/include -L./resources/SDL2/lib -lSDL2  -lSDL2main 

all: $(EXECUTE)

$(EXECUTE): $(OBJ)
	@ mkdir -p '$(@D)'

	@ echo "COMPILING GLAD"
	@ gcc -c ./resources/GLFW/glad/src/glad.c -Wall -Wextra -Werror $(GLAD_INCLUDE)

	@ echo "COMPILING SOURCE $< INTO OBJECT $@"
	clang++ $(FLAGS) -o $@ $^ $(GFLW_FLAGS) glad.o -I $(GLAD_INCLUDE) $(SFML_FLAGS) $(SDL_FLAGS)

$(OBJ_DIR)%.o: %.cpp
	@ mkdir -p '$(@D)'
	clang++ $(FLAGS) -c -o $@ $<

fclean:
	@ rm -rf $(OBJ_DIR)
	@ rm -rf $(EXEPATH)