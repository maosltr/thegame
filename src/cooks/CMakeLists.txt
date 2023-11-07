set(LIBRARY_SOURCES "cooks.cpp")
set(LIBRARY_HEADERS "cooks.hpp")

set(LIBRARY_INCLUDES 
"./" 
"../players"
)
add_library(${COOKS_LIB} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${COOKS_LIB} PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(${COOKS_LIB} PRIVATE ${UTILS_LIB})
target_link_libraries(${COOKS_LIB} PRIVATE ${CONFIG_LIB})
