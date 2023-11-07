set(LIBRARY_SOURCES "config.cpp")
set(LIBRARY_HEADERS "config.hpp")

set(LIBRARY_INCLUDES "./")
add_library(${CONFIG_LIB} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${CONFIG_LIB} PUBLIC ${LIBRARY_INCLUDES})