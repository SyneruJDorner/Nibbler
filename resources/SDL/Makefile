FLAGS = -Wall -Werror -Wextra
SRC = $(shell find . -name *.cpp)
OBJ_DIR = ./obj/
OBJ := $(SRC:%.cpp=$(OBJ_DIR)%.o)
EXEPATH = ./Compiled_Application/
EXECUTE = $(EXEPATH)TestMain

#SDL = -L./lib/ -lSDL2 -lm -liconv -Wl,-framework,OpenGL -Wl,-framework,ForceFeedback -lobjc -Wl,-framework,Cocoa -Wl,-framework,Carbon -Wl,-framework,IOKit -Wl,-framework,CoreAudio -Wl,-framework,AudioToolbox -Wl,-framework,AudioUnit
SDL = -Iinclude  -Llib -lSDL2  -lSDL2main 

all: $(EXECUTE)

$(EXECUTE): $(OBJ)
	@mkdir -p '$(@D)'
	@echo "COMPILING SOURCE $< INTO OBJECT $@"
	g++ -std=c++11 $(FLAGS) -o $@ $^ $(SDL)

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p '$(@D)'
	clang++ -std=c++11 $(FLAGS) -c -o $@ $<

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(EXEPATH)