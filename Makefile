all:
	cmake -S . -B build
	cmake --build build	
run: all
	./build/bin/raytracing
clean:
	rm -rf build
