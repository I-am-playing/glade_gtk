.PHONY: all
all: build

.PHONY: clean
clean:
	rm -rf bin

.PHONY: build
build: | bin
	gcc -o bin/gladewin src/main.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

.PHONY: run
run: build
	./bin/gladewin

bin:
	mkdir -p $@
