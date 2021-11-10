if(NOT PKG_CONFIG_FOUND)
    INCLUDE(FindPkgConfig)
endif()
PKG_CHECK_MODULES(PC_TWOTYPES twoTypes)

FIND_PATH(
    TWOTYPES_INCLUDE_DIRS
    NAMES twoTypes/api.h
    HINTS $ENV{TWOTYPES_DIR}/include
        ${PC_TWOTYPES_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    TWOTYPES_LIBRARIES
    NAMES gnuradio-twoTypes
    HINTS $ENV{TWOTYPES_DIR}/lib
        ${PC_TWOTYPES_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/twoTypesTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TWOTYPES DEFAULT_MSG TWOTYPES_LIBRARIES TWOTYPES_INCLUDE_DIRS)
MARK_AS_ADVANCED(TWOTYPES_LIBRARIES TWOTYPES_INCLUDE_DIRS)
