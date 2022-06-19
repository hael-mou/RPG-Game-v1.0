# files
SRC = $(wildcard src/*.cpp)
HEADER = include
OBJS = ${SRC:.cpp=.o}

# compiler
CC = g++

# flags
CFLAGS = -std=c++14 -m64 -Wall -Wextra -Werror -g
LFLAGS = -lSDL2main -lSDL2 -lSDL2_image

# name of executable
EXEC = RPG_v1

%.o:%.cpp
	${CC} -I ${HEADER} ${CFLAGS} -c $<  -o $@

all: debug drun

debug: ${OBJS}
	${CC} ${OBJS} -o bin/debug/${EXEC} ${LFLAGS}

drun:
	clear
	@./bin/debug/${EXEC}

clear:
	rm -rf  src/*.o

fclear: clear
	rm -rf  bin/debug/${EXEC}

re: fclear all