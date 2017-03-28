
project(dynamicznatablica)

set(HEDEAR_FILES DynamicznaTablica.h)
set(SOURCE_FILES DynamicznaTablica.cpp)

add_library(libdynamicznatablica STATIC ${SOURCE_FILES})
target_include_directories(libdynamicznatablica PUBLIC .)

add_executable(dynamicznatablica ${SOURCE_FILES} main.cpp)

target_link_libraries(dynamicznatablica libdynamicznatablica)