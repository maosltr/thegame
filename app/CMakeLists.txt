set(EXE_SOURCES "main.cpp")

add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})

target_link_libraries(${EXECUTABLE_NAME} PUBLIC 
${CONFIG_LIB}
${PLAYERS_LIB}
${GAME_LIB}
${COOKS_LIB})
