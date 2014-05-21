#The source files we need.
SRCS = dsumHashesToString.cpp dsumCalculateHashes.cpp dsumFilenameParser.cpp main.cpp

#Our C++ compiler, I use clang. Feel feel to change it.
CXX = clang++
GCC = g++

#Lovely compiler flags.
COMPILER_FLAGS = -O3 -std=c++1y -pedantic-errors -Werror

#Libraries we need.
LINKER_FLAGS = -lssl -lcrypto -lz

#OBJ_NAME specifies the name of our exectuable
NAME = dsum


all: $(SRCS)
	make build

build: $(SRCS)
	$(CXX) $(SRCS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(NAME)

# I (DaemonLee) don't normally test with GCC but in theory it should work.
gcc: $(SRCS)
	echo "WARNING: UNTESTED COMPILER! USE WITH CARE!"
	$(GCC) $(SRCS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(NAME)

clean:
	rm $(NAME)

install:
	cp $(NAME) $(INSTALL_PATH)/bin

uninstall:
	rm $(INSTALL_PATH)/bin/$(NAME)