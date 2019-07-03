FLAGS = -Wall -Werror -Wextra
SRC = $(shell find . -name *.cpp)
OBJ_DIR = ./obj/
OBJ := $(SRC:%.cpp=$(OBJ_DIR)%.o)
EXEPATH = ./Compiled_Application/
EXECUTE = $(EXEPATH)Bureaucrat

all: $(EXECUTE)

$(EXECUTE): $(OBJ)
	@mkdir -p '$(@D)'
	@echo "COMPILING SOURCE $< INTO OBJECT $@"
	clang++ $(FLAGS) -o $@ $^

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p '$(@D)'
	clang++ $(FLAGS) -c -o $@ $<

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(EXEPATH)