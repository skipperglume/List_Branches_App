cmake_minimum_required(VERSION 3.12)
project(DisplayRootFiles LANGUAGES CXX)

find_package(ROOT CONFIG REQUIRED)
# Set C++ standard
# set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/.)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/.)
include("${ROOT_USE_FILE}")

# Source files
set(SOURCES
    src/DisplayRootFile.cxx
    
)

# Header files
set(HEADERS
    include/DisplayRootFile_H.h
)

# Add the executable

add_library(Display SHARED ${SOURCES} ${HEADERS})
add_executable(Dsply main.cpp )
# Set include directories
# target_include_directories(Dsply PRIVATE include)
target_link_libraries(Dsply PUBLIC ${ROOT_LIBRARIES})
target_link_libraries(Dsply PRIVATE Display)
message(${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "include dir: ${CMAKE_CURRENT_SOURCE_DIR}")



# same C++ standard as ROOT was compiled with.

# Create the main program using the library.
   #add_executable(Main MainEvent.cxx)
   #target_link_libraries(Main Event)