#!/bin/bash
rm Google_Tests_run 2>/dev/null
cmake CMakeLists.txt && make && ./Google_Tests_run
rm -R CMakeFiles
rm CMakeCache.txt cmake_install.cmake Makefile
