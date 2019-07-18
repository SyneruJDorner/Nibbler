FLAGS = -Wall -Werror -Wextra 
SRC = 	LibSDL2.cpp \
		../utils/Exceptions/GraphicLibraryExceptions.cpp
OBJ_DIR = ./obj/
OBJ := $(SRC:%.cpp=$(OBJ_DIR)%.o)
EXEPATH = ../../../libraries/
EXECUTE = $(EXEPATH)libSDL2.so

SDL_INCLUDE = -I../../SDL2/include
SDL_FLAGS = $(SDL_INCLUDE) -L../../SDL2/lib -lSDL2  -lSDL2main 

all: $(EXECUTE)

$(EXECUTE): $(OBJ)
	@ mkdir -p '$(@D)'

	@ echo "COMPILING SOURCE $< INTO DYNAMIC LIBRARY $@"
	clang++ $(FLAGS) -std=c++0x -shared -fPIC -o $@ $^ $(SDL_FLAGS)

$(OBJ_DIR)%.o: %.cpp
	@ mkdir -p '$(@D)'
	clang++ $(FLAGS) $(SDL_INCLUDE) -c -o $@ $<

fclean:
	@ rm -rf $(OBJ_DIR)
	@ rm -rf $(EXECUTE)
	@ rm -rf utils