
.PHONY: build
build:
	mkdir -p dist
	g++ -Wall -Wextra -pedantic-errors -O3 -std=gnu++2a -o dist/app source/functions.cpp source/main.cpp

.PHONY: test1
test:
	mkdir -p dist
	g++  -Wall -Wextra -pedantic-errors -std=gnu++2a -o dist/test1 source/functions.cpp test/test1.cpp
	dist/test1

.PHONY: test2
test:
	mkdir -p dist
	g++  -Wall -Wextra -pedantic-errors -std=gnu++2a -o dist/test2 source/functions.cpp test/test2.cpp
	dist/test2

.PHONY: clean
clean:
	rm -rf dist
