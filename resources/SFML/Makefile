FLAGS = -Wall -Werror -Wextra
SRC = $(shell find . -name *.cpp)
OBJ_DIR = ./obj/
OBJ := $(SRC:%.cpp=$(OBJ_DIR)%.o)
EXEPATH = ./Compiled_Application/
EXECUTE = $(EXEPATH)TestMain

SFML = -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system

all: $(EXECUTE)

$(EXECUTE): $(OBJ)
	@mkdir -p '$(@D)'
	@echo "COMPILING SOURCE $< INTO OBJECT $@"
	g++ -std=c++11 $(FLAGS) -o $@ $^ $(SFML)

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p '$(@D)'
	g++ -std=c++11 $(FLAGS) -c -o $@ $<

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(EXEPATH)