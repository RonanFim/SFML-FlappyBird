# In order to link statically, it is necessary to recompile the library with cmake
# https://www.youtube.com/watch?v=UM93glM0Fhs

#
# Makefile
#
# make			: Build the exe and remove the .o and .d files created in the process
# make debug	: Build the exe, but keep the .o and .d files (for developers)
# make clear	: Remove the .o and .d files created by "make debug"
# make clearall	: Remove the .exe, .o and .d files
# make remake	: Clear all and recompile
#

ifeq ($(OS),Windows_NT)
EXE_FILE = FlappyBird.exe
SFML_PATH = C:/SFML-2.5.1
else
EXE_FILE = FlappyBird.out
SFML_PATH = /home/ronan/SFML-2.5.1
endif

INCLUDE_DIR = $(SFML_PATH)/include
LIB_DIR = $(SFML_PATH)/lib

CC = g++
ifeq ($(OS),Windows_NT)
LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype
else
LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lGL -lglut -lX11 -lXrandr -ludev -lfreetype -lpthread
endif
DEFS = -DSFML_STATIC

CPPFLAGS = $(DEFS) -I$(INCLUDE_DIR)
LDFLAGS = $(DEFS) -L$(LIB_DIR) $(LIBS)

CPPSOURCESALL = $(wildcard *.cpp */*.cpp */*/*.cpp */*/*/*.cpp */*/*/*/*.cpp)
CPP_IGNORE = .vscode/%
CPPSOURCES = $(filter-out $(CPP_IGNORE), $(CPPSOURCESALL))

# Build the exe and remove the objects created in the compiling process
all: $(EXE_FILE)
	$(MAKE) clear

# Build the exe and keep the objects. For developing
debug: $(EXE_FILE)

# Remove the compiling objects
clear:
	rm -f $(CPPSOURCES:.cpp=.o) $(CPPSOURCES:.cpp=.d)

# Remove the compiling objects and the .exe
clearall:
	$(MAKE) clear
	rm $(EXE_FILE)

# Clear all and recompile
remake:
	$(MAKE) clearall
	$(MAKE)


# Linker to build .exe
$(EXE_FILE): $(CPPSOURCES:.cpp=.o)
	$(CC) -o $@ $^ $(LDFLAGS)

# Compile .cpp files
%.o: %.cpp
	$(CC) -c $< $(CPPFLAGS) -o $@

# Create the dependencies files (.d) related to the .cpp files
# This files tell what are the dependencies of each of the code files
# If any dependency were changed, the .cpp file will be recompiled
-include $(CPPSOURCES:.cpp=.d)

%.d: %.cpp
	$(CC) $< -MM -MT '$*.o $*.d' -MD $(CPPFLAGS) -o $@
