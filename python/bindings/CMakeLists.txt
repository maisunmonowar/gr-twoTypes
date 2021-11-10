# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT twoTypes_sources)
    MESSAGE(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT twoTypes_sources)

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################
include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11
    GIT_TAG        v2.6.1
)
FetchContent_MakeAvailable(pybind11)
list(APPEND twoTypes_python_files
    passthrough_python.cc python_bindings.cc)

GR_PYBIND_MAKE_OOT(twoTypes 
   ../..
   gr::twoTypes
   "${twoTypes_python_files}")

install(TARGETS twoTypes_python DESTINATION ${GR_PYTHON_DIR}/twoTypes COMPONENT pythonapi)
