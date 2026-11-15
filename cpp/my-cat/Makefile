CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -O2

mycat: mycat.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

test: mycat
	./mycat /bin/ls | cmp - /bin/ls && echo "binary OK"
	echo hi | ./mycat | grep -qx hi && echo "stdin OK"

clean:
	rm -f mycat
