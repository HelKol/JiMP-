
project(moviesubtitles)

set(HEDEAR_FILES MicroDvdSubtitles.h Exception.h)
set(SOURCE_FILES MicroDvdSubtitles.cpp Exception.cpp)

add_library(libmoviesubtitles STATIC ${SOURCE_FILES})
target_include_directories(libmoviesubtitles PUBLIC .)

add_executable(moviesubtitles ${SOURCE_FILES} main.cpp)

target_link_libraries(moviesubtitles libmoviesubtitles)
