/*	dsum - A universal hash integrity checker with an automatic file name parser for commonly checked things.
	Copyright (C) 2014  Daemon Lee Schmidt

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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