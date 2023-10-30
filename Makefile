prepare:
	rm -rf build
	mkdir build
	cd build && \
	cmake .. && \
	cmake --build . # --target menu_lib balance_lib deposit_lib withdraw_lib
    