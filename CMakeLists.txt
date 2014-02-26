CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)
PROJECT(cppBioCheN)

INCLUDE_DIRECTORIES( include )

ADD_SUBDIRECTORY(src)
#ADD_SUBDIRECTORY(test)

ADD_DEFINITIONS( --std=c++11 )

#add_library(matrix SHARED
#include/
#src/
#)

#ADD_EXECUTABLE( hh-model src/ )
ADD_EXECUTABLE(matrix src/matrix-
#target_link_libraries( hh-model mgl gsl)
