cmake_minimum_required(VERSION 2.8.12)
project(examples C)

add_executable(compress_all compress_all.c)
add_executable(extract_all extract_all.c)
add_executable(make_new make_new.c)
target_link_libraries(compress_all grf_static)
target_link_libraries(extract_all grf_static)
target_link_libraries(make_new grf_static)
