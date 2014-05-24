#The source files we need.
SRCS = calculateHashes.cpp filenameParser.cpp main.cpp

#Our C++ compiler, I use clang. Feel feel to change it.
CXX = clang++
GCC = g++

#Lovely compiler flags.
COMPILER_FLAGS = -O3 -std=c++1y -pedantic-errors -Werror -Wall -W

#Libraries we need.
LINKER_FLAGS = -lssl -lcrypto -lz

#NAME is the name of the exectuable
NAME = dsum


all: $(SRCS)
	make build

build: $(SRCS)
	$(CXX) $(SRCS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(NAME)

# I (DaemonLee) don't normally test or build dsum with GCC but in theory it should work.
gcc: $(SRCS)
	echo "WARNING: UNTESTED COMPILER! USE WITH CARE!"
	$(GCC) $(SRCS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(NAME)

debug:
	$(CXX) $(SRCS) $(COMPILER_FLAGS) -g $(LINKER_FLAGS) -o $(NAME)-debug

clean:
	rm $(NAME)

install:
	cp $(NAME) $(INSTALL_PATH)/bin

uninstall:
	rm $(INSTALL_PATH)/bin/$(NAME)