set(LIBRARY_SOURCES "players.cpp")
set(LIBRARY_HEADERS "players.hpp")

add_library(${PLAYERS_LIB} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${PLAYERS_LIB} PUBLIC
"./")