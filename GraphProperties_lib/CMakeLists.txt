project(GraphProperties)

set(HEADER_FILES DataReader.h)

set(SOURCE_FILES DataReader.cpp)

add_library(GraphProperties_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
