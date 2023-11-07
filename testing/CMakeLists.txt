set(TEST_MAIN "unit_tests")
set(TEST_SOURCES "main.cpp")
set(TEST_INCLUDES "./")

add_executable(${TEST_MAIN} ${TEST_SOURCES})
target_include_directories(${TEST_MAIN} PUBLIC ${TEST_INCLUDES})
target_link_libraries(${TEST_MAIN} PUBLIC 
${PLAYERS_LIB} 
${GAME_LIB} 
${COOKS_LIB} 
${CONFIG_LIB}
Catch2::Catch2)