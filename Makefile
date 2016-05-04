build:
	g++ -o main main.cpp src/*.cpp -I/usr/include/SDL/ -I include/ -lSDL -lSDL_image -lSDL_gfx -lSDL_ttf -lstdc++
