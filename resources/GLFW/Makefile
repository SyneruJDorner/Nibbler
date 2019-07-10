FLAGS = -Wall -Werror -Wextra
SRC = $(shell find . -name *.cpp)
OBJ_DIR = ./obj/
OBJ := $(SRC:%.cpp=$(OBJ_DIR)%.o)
EXEPATH = ./Compiled_Application/
EXECUTE = $(EXEPATH)TestMain

GLFW3 = -L./lib/ -I./include/GLFW -lglfw -framework OpenGL -framework IOKit -framework CoreVideo

all: $(EXECUTE)

$(EXECUTE): $(OBJ)
	@mkdir -p '$(@D)'
	@echo "COMPILING SOURCE $< INTO OBJECT $@"
	clang++ -std=c++11 $(FLAGS) -o $@ $^ $(GLFW3)

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p '$(@D)'
	clang++ -std=c++11 $(FLAGS) -c -o $@ $<

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(EXEPATH)