set(LIBRARY_SOURCES "utils.cpp")
set(LIBRARY_HEADERS "utils.hpp")


add_library(${UTILS_LIB} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${UTILS_LIB} PUBLIC 
"./")