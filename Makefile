all:
	mkdir -p build
	gcc src/*.c -o build/bf

clean:
	rm -rf build/
