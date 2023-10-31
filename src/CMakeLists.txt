set(LIBRARY_SOURCES "players.cpp" "game.cpp")
set(LIBRARY_HEADERS "players.hpp" "game.hpp")


add_library(${GAME_LIB} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${GAME_LIB} PUBLIC "./")