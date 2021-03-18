EXENAME = main
OBJS = main.o graph.o

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME) cleanobj

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: main.cpp
	$(CXX) $< $(CXXFLAGS)

graph.o: graph.cpp graph.h
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -f *.o *.gch $(EXENAME)

cleanobj:
	-rm -f *.o *.gch
