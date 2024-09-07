all:
	g++ -o main main.cpp

nchw: nchw.cpp
	g++ -o nchw nchw.cpp -lncurses

ncBlocks: ncBlocks.cpp
	g++ -o ncBlocks ncBlocks.cpp -lncurses

ncmouse: ncmouse.cpp
	g++ -o ncmouse ncmouse.cpp -lncurses

p2: p2.cpp
	g++ -o p2 p2.cpp -lncurses

p3: p3.cpp
	g++ -o p3 p3.cpp -lncurses