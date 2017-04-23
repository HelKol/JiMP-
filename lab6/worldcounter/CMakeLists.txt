
project(worldcounter)

set(HEDEAR_FILES WorldCounter.h)
set(SOURCE_FILES WorldCounter.cpp)

add_library(libworldcounter STATIC ${SOURCE_FILES})
target_include_directories(libworldcounter PUBLIC .)

add_executable(worldcounter ${SOURCE_FILES} main.cpp)

target_link_libraries(worldcounter libworldcounter)
