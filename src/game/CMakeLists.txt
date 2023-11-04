set(LIBRARY_SOURCES "game.cpp")
set(LIBRARY_HEADERS "game.hpp")


add_library(${GAME_LIB} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${GAME_LIB} PUBLIC 
"./" 
"../cooks"
"../players")