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

p4: p4.cpp
	g++ -o p4 p4.cpp -lncurses

p5: p5.cpp
	g++ -o p5 p5.cpp -lncurses

lab05-p1: lab05-p1.cpp
	g++ -o lab05-p1 lab05-p1.cpp -lncurses
