FLAGS = -Wall -Werror -Wextra 
SRC = 	LibSFML.cpp \
		../utils/Exceptions/GraphicLibraryExceptions.cpp
OBJ_DIR = ./obj/
OBJ := $(SRC:%.cpp=$(OBJ_DIR)%.o)
EXEPATH = ../../../Libraries/
EXECUTE = $(EXEPATH)libSFML.so

GLAD_INCLUDE = -I ../../GLFW/glad/include

SFML_INCLUDE = -I ../../SFML/include
SFML_FLAGS =   $(SFML_INCLUDE) -L ../../SFML/lib/ -lsfml-graphics -lsfml-window -lsfml-system

all: $(EXECUTE)

$(EXECUTE): $(OBJ)
	@ mkdir -p '$(@D)'

	@ echo "COMPILING SOURCE $< INTO DYNAMIC LIBRARY $@"
	clang++ $(FLAGS) -std=c++0x  -shared -fPIC -o $@ $^ $(SFML_FLAGS)

$(OBJ_DIR)%.o: %.cpp
	@ mkdir -p '$(@D)'
	clang++ $(FLAGS) -std=c++0x  $(SFML_INCLUDE) -c -o $@ $<

fclean:
	@ rm -rf $(OBJ_DIR)
	@ rm -rf $(EXECUTE)
	@ rm -rf utils