CC = g++
CPPFLAGS = -g -Wall -Wextra -std=c++17 -pedantic

build:
	${CC} ${CPPFLAGS} -o bin/${FILE} src/${FILE}.cpp

run: build
	@echo "----------------------"
	@echo
	@./bin/${FILE}

clean:
	rm -f bin/*

prepare:
	@echo "Creating day${DAY}..."
	@curl https://adventofcode.com/2023/day/${DAY}/input -H "Cookie: session=$(shell cat .env)" > res/day${DAY}.txt
	@cp src/template.cpp src/day${DAY}.cpp
