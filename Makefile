# In order to link statically, it would be necessary recompile the library with cmake
# https://www.youtube.com/watch?v=UM93glM0Fhs

EXE_FILE = FlappyBird.exe
PROGRAM_PATH = C:/SFML-2.5.1
INCLUDE_DIR = $(PROGRAM_PATH)/include
LIB_DIR = $(PROGRAM_PATH)/lib

CC = g++
LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype
DEFS = -DSFML_STATIC

CPPFLAGS = $(DEFS) -I$(INCLUDE_DIR)
LDFLAGS = $(DEFS) -L$(LIB_DIR) $(LIBS)

CPPSOURCES = $(wildcard *.cpp)

all: $(EXE_FILE)

$(EXE_FILE): $(CPPSOURCES:.cpp=.o)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $< $(CPPFLAGS) -o $@

clear:
	rm -f *.o *.d

clearall:
	$(MAKE) clear
	rm -f "$(EXE_FILE)"

remade:
	$(MAKE) clearall
	$(MAKE)

-include $(CPPSOURCES:.cpp=.d)

%.d: %.cpp
	$(CC) $< -MM -MT '$*.o $*.d' -MD $(CPPFLAGS)
