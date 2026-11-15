CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -O2

mywc: mywc.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

test: mywc
	echo "hello world" | ./mywc
	./mywc mywc.cpp

clean:
	rm -f mywc