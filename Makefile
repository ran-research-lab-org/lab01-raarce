all:
	g++ -o main main.cpp

nchw: nchw.cpp
	g++ -o nchw nchw.cpp -lncurses

ncBlocks: ncBlocks.cpp
	g++ -o ncBlocks ncBlocks.cpp -lncurses

ncmouse: ncmouse.cpp
	g++ -o ncmouse ncmouse.cpp -lncurses