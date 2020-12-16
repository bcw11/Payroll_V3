
all: main

run: main
	./main

main: main.o helper.o user.o datetime.o date.o time.o
	g++ -g -o main main.o helper.o user.o datetime.o date.o time.o

main.o: main.cpp
	g++ -g -c main.cpp -std=c++11

helper.o: helper.cpp
	g++ -g -c helper.cpp -std=c++11

user.o: user.cpp
	g++ -g -c user.cpp -std=c++11

datetime.o: datetime.cpp
	g++ -g -c datetime.cpp -std=c++11

date.o: date.cpp
	g++ -g -c date.cpp -std=c++11

time.o: time.cpp
	g++ -g -c time.cpp -std=c++11

clean:
	del main.exe main.o helper.o user.o datetime.o date.o time.o *~