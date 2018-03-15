CXX = g++
CXXFLAGS = -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -std=c++11

SRCS = *.cpp
HEADERS = *.hpp
OBJS = *.o


All: ${OBJS} main

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -c

main: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

clean:
	rm *.o main
