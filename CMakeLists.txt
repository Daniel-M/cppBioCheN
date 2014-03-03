CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)
PROJECT(cppBioCheN)

INCLUDE_DIRECTORIES( include )

#ADD_SUBDIRECTORY(src)
#ADD_SUBDIRECTORY(test)

ADD_DEFINITIONS( --std=c++11 )

#add_library(matrix SHARED
#include/
#src/
#)

#ADD_EXECUTABLE( hh-model src/ )
ADD_EXECUTABLE(matrix src/matrix-function)
ADD_EXECUTABLE(test-parser src/test)
ADD_EXECUTABLE(boost-parser src/boost_test)
#ADD_EXECUTABLE(matrix src/matrix-function)
#target_link_libraries( matrix libmatrix)
