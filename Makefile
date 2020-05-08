# Complete ex: https://stackoverflow.com/questions/20934968/mingw-static-library-linking-sfml-2-1/24575912

# FlappyBird.exe: main.o
# 	g++ -DSFML_STATIC main.o -o FlappyBird.exe -LC:/SFML-2.5.1/lib -lsfml-system-s -lsfml-window-s -lsfml-graphics-s

# main.o: main.cpp
# 	g++ -DSFML_STATIC -c main.cpp -IC:/SFML-2.5.1/include

FlappyBird.exe: main.o
	g++ main.o -o FlappyBird.exe -DSFML_STATIC -LC:/SFML-2.5.1/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype

main.o: main.cpp
	g++ -c main.cpp -DSFML_STATIC -IC:/SFML-2.5.1/include

all: FlappyBird.exe

clear:
	rm "FlappyBird.exe" "main.o"

clean:
	rm "main.o"