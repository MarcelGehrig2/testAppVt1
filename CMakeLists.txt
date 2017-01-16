# cmake_minimum_required(VERSION 2.6)
# project(testappvt1)
# 
# add_executable(testappvt1 main.cpp)
# 
# install(TARGETS testappvt1 RUNTIME DESTINATION bin)


cmake_minimum_required(VERSION 2.8)
 
project(testappvt1)
 
find_package(EEROS REQUIRED)
include_directories(${EEROS_INCLUDE_DIR})
link_directories(${EEROS_LIB_DIR})
 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
 
add_executable(testappvt1
	main.cpp
	
	sequences/MainSequence.cpp
	sequences/SequenceA.cpp
	sequences/SequenceB.cpp
)




target_link_libraries(testappvt1 eeros)
add_subdirectory(sequences)