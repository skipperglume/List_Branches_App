cmake_minimum_required(VERSION 3.12)
project(DisplayRootFiles LANGUAGES CXX)

find_package(ROOT CONFIG REQUIRED)
# set(CMAKE_CXX_STANDARD 17)

# include_directories(./src)
# include_directories(./)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories(./include)
include("${ROOT_USE_FILE}")
# Set C++ standard

# Source files
set(SOURCES
    src/DisplayRootFile.cxx
    # main.cpp
)

# Header files
set(HEADERS
    include/DisplayRootFile_H.h
)

# Add the executable
add_executable(Dsply main.cpp src/DisplayRootFile.cxx include/DisplayRootFile_H.h)
# CMAKE_CURRENT_SOURCE_DIR
# Set include directories
# target_include_directories(Dsply PRIVATE include)
target_link_libraries(Dsply PUBLIC ${ROOT_LIBRARIES})





# Locate the ROOT package and define a number of useful targets and variables.

# Create a shared library.
# Passing cmake targets such as `ROOT::RIO` as dependencies (rather than plain
# library names for example via ${ROOT_LIBRARIES}) ensures that properties such as required
# include directories and C++ standard are propagated to our libraries or executables.
# Note: To ensure compatibility with Cling, targets *must* be compiled using the
# same C++ standard as ROOT was compiled with.
   #add_library(Event SHARED Event.cxx)
   #t#arget_link_libraries(Event PUBLIC ROOT::RIO ROOT::Net)

# Create the main program using the library.
   #add_executable(Main MainEvent.cxx)
   #target_link_libraries(Main Event)