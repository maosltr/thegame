set(LIBRARY_SOURCES "players.cpp" "game.cpp" "cooks.cpp")
set(LIBRARY_HEADERS "players.hpp" "game.hpp" "cooks.hpp")


add_library(${GAME_LIB} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${GAME_LIB} PUBLIC "./")