.PHONY: all
all: bin/gladewin
	@echo "" > /dev/null

.PHONY: clean
clean:
	rm -rf bin

.PHONY: build
bin/gladewin: src/main.c | bin
	gcc -o $@ $< -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

.PHONY: run
run: bin/gladewin
	@./$<

bin:
	mkdir -p $@
