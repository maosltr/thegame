prepare:
	rm -rf build
	rm -rf docs/html
	mkdir build

build_app:
	cd build && \
	cmake  -DCMAKE_BUILD_TYPE=Debug .. && \
	make -j4
	
debug_app:
	gdb build/app/theGame

dependency:
	cd build && cmake .. --graphviz=graph.dot && dot -Tpng graph.dot -o graphImage.png

play:
	./build/app/theGame

analyze:
	find . -name "*.[ch]pp" | xargs wc -l

documentation:
	cd docs && \
	doxygen

tests:
	./build/testing/unit_tests