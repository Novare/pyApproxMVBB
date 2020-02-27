cmake_minimum_required(VERSION 2.8.12)
project(pyApproxMVBB)

set(PYBIND11_CPP_STANDARD -std=c++11)
set(PYBIND11_PYTHON_VERSION 3.6)

add_subdirectory(pybind11)
pybind11_add_module(pyApproxMVBB MODULE NO_EXTRAS pyApproxMVBB.cpp)
target_include_directories(pyApproxMVBB PUBLIC "/usr/include/eigen3")
target_link_libraries(pyApproxMVBB PUBLIC ApproxMVBB)
