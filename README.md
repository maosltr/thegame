# thegame
 
# Debug mode

rm -rf build
	mkdir build
	cd build && \
	cmake  -DCMAKE_BUILD_TYPE=Debug .. && \
	cmake --build .

gdb build/app/theGame
b 20
b cooks.cpp:20
run 
info b
b list::erase
b 20
b cooks.cpp:20
where
frame
c
next 
step

