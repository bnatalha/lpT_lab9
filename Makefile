##by @bnatalha.

# - - - - - - - - - - - - - - - - - - - -
# - - ---------- VARIABLES ---------- - -
# - - - - - - - - - - - - - - - - - - - -

# Directories
INC_DIR =include
SRC_DIR =src
OBJ_DIR =build
LIB_DIR =lib

# Compilation flags
CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0 -g -I $(INC_DIR)

# Compilators
CC =g++
AR =ar

# - - - - - - - - - - - - - - - - - - - -
# - - ----------- TARGETS ----------- - -
# - - - - - - - - - - - - - - - - - - - -

# =============== PHONY =================
#.PHONY: windows linux init val clean docs
.PHONY: linux init val clean docs

# Generates the necessary filse for this library to run on a (Debian based) linux system
linux: natalia.a natalia.so prog_estatico prog_dinamico

# Creates the 'build' and the 'lib' folder at the current directory if there's no other folder with this name on it.
init:
	mkdir -p build ;\
	mkdir -p lib

# ============ DOCUMENTATION ==============
# Creates the 'docs' folder at the current directory if there's no other folder with this name on it.
# Generates .html documentation via doxygen at the folder 'docs'
docs: Doxyfile
	mkdir -p docs ;\
	doxygen	

# ============== VALGRIND =================
# Runs valgrind with 'build/prog_estatico'
vals:
	valgrind --leak-check=yes build/prog_estatico

# Runs valgrind with 'build/prog_dinamico'
vald:
	valgrind --leak-check=yes build/prog_dinamico

# LINUX

natalia.a: $(SRC_DIR)/func_ordem.cpp $(INC_DIR)/myPilha.h $(INC_DIR)/header.h
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/func_ordem.cpp -o $(OBJ_DIR)/func_ordem.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/func_ordem.o
	@echo "++++++ [Biblioteca estática criada em $(LIB_DIR)/$@] ++++++"

natalia.so: $(SRC_DIR)/func_ordem.cpp $(INC_DIR)/myPilha.h $(INC_DIR)/header.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC_DIR)/func_ordem.cpp -o $(OBJ_DIR)/func_ordem.o
	$(CC) -shared -fPIC -o $(LIB_DIR)/$@ $(OBJ_DIR)/func_ordem.o
	@echo "++++++ [Biblioteca dinâmica criada em $(LIB_DIR)/$@] ++++++"

prog_estatico:
	$(CC) $(CPPFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/natalia.a -o $(OBJ_DIR)/$@

prog_dinamico:
	$(CC) $(CPPFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/natalia.so -o $(OBJ_DIR)/$@


# ================ CLEANER ================
# Removes objects
clean:
	$(RM) build/*.o 