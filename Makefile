
.PHONY: build
build:
	mkdir -p dist
	g++ -Wall -Wextra -pedantic-errors -O3 -std=gnu++2a -o dist/app source/functions.cpp source/main.cpp

.PHONY: test
test:
	mkdir -p dist
	g++  -Wall -Wextra -pedantic-errors -std=gnu++2a -o dist/test source/functions.cpp test/test.cpp
	dist/test

.PHONY: clean
clean:
	rm -rf dist
