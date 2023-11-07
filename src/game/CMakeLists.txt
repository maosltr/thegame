set(LIBRARY_SOURCES "game.cpp")
set(LIBRARY_HEADERS "game.hpp")

set(LIBRARY_INCLUDES 
"./" 
"../cooks"
"../players")

add_library(${GAME_LIB} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})

target_include_directories(${GAME_LIB} PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(${GAME_LIB} PRIVATE ${CONFIG_LIB})
