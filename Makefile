prepare:
	rm -rf build
	mkdir build

build:
	cd build && \
	cmake  -DCMAKE_BUILD_TYPE=Debug .. && \
	cmake --build .

dependency:
	cd build && cmake .. --graphviz=graph.dot && dot -Tpng graph.dot -o graphImage.png