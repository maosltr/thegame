set(LIBRARY_SOURCES "cooks.cpp")
set(LIBRARY_HEADERS "cooks.hpp")


add_library(${COOKS_LIB} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${COOKS_LIB} PUBLIC 
"./" 
"../players"
)