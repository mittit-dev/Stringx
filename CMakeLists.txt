cmake_minimum_required(VERSION 3.10)
project(Stringx C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(INCLUDE_INSTALL_DIR include)
set(LIB_INSTALL_DIR lib)

set(SOURCES
    src/stringx.c
    src/boolx.c
)

set(HEADERS
    include/stringx.h
    include/boolx.h
)

add_library(Stringx_static STATIC ${SOURCES})
add_library(Stringx_shared SHARED ${SOURCES})

target_include_directories(Stringx_static PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${INCLUDE_INSTALL_DIR}>
)

target_include_directories(Stringx_shared PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${INCLUDE_INSTALL_DIR}>
)

install(TARGETS Stringx_static
    ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
)

install(TARGETS Stringx_shared
    LIBRARY DESTINATION ${LIB_INSTALL_DIR}
    RUNTIME DESTINATION bin
)

install(FILES ${HEADERS} DESTINATION ${INCLUDE_INSTALL_DIR})
