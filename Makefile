#The source files we need.
SRCS = dsumHashesToString.cpp dsumCalculateHashes.cpp main.cpp

#Our C++ compiler, I use clang. Feel feel to change it.
CXX = clang++

#Lovely compiler flags.
COMPILER_FLAGS = -O3 -std=c++11 -pedantic-errors -Werror

#Libraries we need.
LINKER_FLAGS = -lssl -lcrypto -lz

#OBJ_NAME specifies the name of our exectuable
NAME = dsum


all: $(SRCS)
	make build

build: $(SRCS)
	$(CXX) $(SRCS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(NAME)

clean:
	rm $(NAME)

install:
	cp $(NAME) $(INSTALL_PATH)/bin

uninstall:
	rm $(INSTALL_PATH)/bin/$(NAME)