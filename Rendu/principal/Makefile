
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror

%.o: %.cpp %.hpp %.h
	$(CXX) $(CXXFLAGS) $< -c -o $@

main: main.o
	$(CXX) $< -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core
