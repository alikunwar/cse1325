CXXFLAGS = --std=c++17

all: coin

color: main.o coin.o *.h
	$(CXX) $(CXXFLAGS) test.o coin.o -o coin


test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o
coin.o: coin.cpp
	$(CXX) $(CXXFLAGS) -c coin.cpp -o coin.o


coin.gch: coin.h
	$(CXX) $(CXXFLAGS) -c coin.h -o coin.gch

logger.gch: logger.h
	$(CXX) $(CXXFLAGS) -c logger.h -o logger.gch

clean:
	rm -f *.o *.gch *~coin