CXXFLAGS = --std=c++17

all: main

main: main.o item.o cart.o
	$(CXX) $(CXXFLAGS) main.o item.o cart.o -o main

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

item.o: item.cpp *.h
	$(CXX) $(CXXFLAGS) -c item.cpp -o item.o
	
cart.o: cart.cpp *.h
	$(CXX) $(CXXFLAGS) -c cart.cpp -o cart.o

clean:
	rm -f *.o *.gch main
	

	
	
