FLAGS = -Wall -Werror -Wextra 
SRC = 	LibGLFW.cpp \
		../utils/Exceptions/GraphicLibraryExceptions.cpp
OBJ_DIR = ./obj/
OBJ := $(SRC:%.cpp=$(OBJ_DIR)%.o)
EXEPATH = ../../../Libraries/
EXECUTE = $(EXEPATH)libGLFW.so

GLAD_INCLUDE = -I../../GLFW/glad/include

GLFW_INCLUDE = -I../../GLFW/include
GFLW_FLAGS =  $(GLFW_INCLUDE) -L../../GLFW/lib/ -lglfw -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

all: $(EXECUTE)

$(EXECUTE): $(OBJ)
	@ mkdir -p '$(@D)'

	@ echo "COMPILING GLAD"
	@ gcc -c ../../GLFW/glad/src/glad.c $(FLAGS) $(GLAD_INCLUDE)

	@ echo "COMPILING SOURCE $< INTO DYNAMIC LIBRARY $@"
	clang++ $(FLAGS) -std=c++0x  -shared -fPIC -o $@ $^ glad.o $(GFLW_FLAGS) $(GLAD_INCLUDE)

$(OBJ_DIR)%.o: %.cpp
	@ mkdir -p '$(@D)'
	clang++ $(FLAGS) -std=c++0x  $(GLAD_INCLUDE) $(GLFW_INCLUDE) -c -o $@ $<

fclean:
	@ rm -rf $(OBJ_DIR)
	@ rm -rf $(EXECUTE)
	@ rm -rf glad.o
	@ rm -rf utils