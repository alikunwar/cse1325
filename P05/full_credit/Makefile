CXXFLAGS = --std=c++17

all: product 

product: main.o product.o  taxfree.o taxed.o *.h
	$(CXX) $(CXXFLAGS) main.o product.o taxfree.o taxed.o  -o product


main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
product.o: product.cpp *.h
	$(CXX) $(CXXFLAGS) -c product.cpp -o product.o
taxed.o: taxed.cpp *.h
	$(CXX) $(CXXFLAGS) -c taxed.cpp -o taxed.o
taxfree.o: taxfree.cpp *.h
	$(CXX) $(CXXFLAGS) -c taxfree.cpp -o taxfree.o


product.gch: product.h
	$(CXX) $(CXXFLAGS) -c product.h -o product.gch
taxed.gch: taxed.h
	$(CXX) $(CXXFLAGS) -c taxed.h -o taxed.gch
taxfree.gch: taxfree.h
	$(CXX) $(CXXFLAGS) -c taxfree.h -o taxfree.gch

clean:
	rm -f *.o *.gch ~* a.out product
