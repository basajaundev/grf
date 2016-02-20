cmake_minimum_required(VERSION 2.8.12)
project(libgrf C)

set(LIBGRF_MAJOR_VERSION 0)
set(LIBGRF_MINOR_VERSION 1)
set(LIBGRF_PATCH_VERSION 31)
set(LIBGRF_VERSION "${LIBGRF_MAJOR_VERSION}.${LIBGRF_MINOR_VERSION}.${LIBGRF_PATCH_VERSION}")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/static")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/shared")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/binary")

set(INSTALL_LIB_DIR     "lib"           CACHE PATH "Installation directory for libraries")
set(INSTALL_PKGCONF_DIR "lib/pkgconfig" CACHE PATH "Installation directory for pkg-config files")
set(INSTALL_INCLUDE_DIR "include"       CACHE PATH "Installation directory for header files")

find_package(ZLIB REQUIRED)

file(GLOB SRCS "${CMAKE_SOURCE_DIR}/src/*.c")
file(GLOB INCS "${CMAKE_SOURCE_DIR}/includes/*.h")

include_directories("${ZLIB_INCLUDE_DIRS}")
include_directories("${CMAKE_SOURCE_DIR}/includes")
add_library(grf_static STATIC ${SRCS})
add_library(grf_shared SHARED ${SRCS})
target_link_libraries(grf_static ${ZLIB_LIBRARIES})
target_link_libraries(grf_shared ${ZLIB_LIBRARIES})
set_target_properties(grf_static PROPERTIES C_STANDARD 99)
set_target_properties(grf_shared PROPERTIES C_STANDARD 99)
set_target_properties(grf_static PROPERTIES OUTPUT_NAME grf)
set_target_properties(grf_shared PROPERTIES OUTPUT_NAME grf)
set_target_properties(grf_shared PROPERTIES IMPORT_SUFFIX .lib)
set_target_properties(grf_shared PROPERTIES VERSION ${LIBGRF_MAJOR_VERSION} SOVERSION ${LIBGRF_VERSION})

add_subdirectory(grfbuilder)
add_subdirectory(examples)

install(TARGETS grf_static DESTINATION ${INSTALL_LIB_DIR})
install(TARGETS grf_shared DESTINATION ${INSTALL_LIB_DIR})
install(FILES ${INCS} DESTINATION ${INSTALL_INCLUDE_DIR})
