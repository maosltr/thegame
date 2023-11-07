set(LIBRARY_SOURCES "players.cpp")
set(LIBRARY_HEADERS "players.hpp")
set(LIBRARY_INCLUDES 
"./" 
)

add_library(${PLAYERS_LIB} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${PLAYERS_LIB} PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(${PLAYERS_LIB} PRIVATE ${UTILS_LIB})
target_link_libraries(${PLAYERS_LIB} PRIVATE ${CONFIG_LIB})