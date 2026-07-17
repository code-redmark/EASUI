cmake_minimum_required(VERSION 3.15)
project(EAS_TEST_1)


# second argument can be omitted if library folder isnt outside of project root folder
add_subdirectory("../../EASUI" ${CMAKE_BINARY_DIR}/EASUI) 

add_executable(example
	TEST.c
)

target_link_libraries(example PRIVATE EASUI)