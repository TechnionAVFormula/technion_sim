# Copyright (c) 2016-2019 NVIDIA CORPORATION.  All rights reserved.

cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)
project(TechnionSim C CXX)
#-------------------------------------------------------------------------------
# Set basic configurations
#-------------------------------------------------------------------------------
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)


set(FORMULA_AV_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(FORMULA_AV_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})     


find_package(Protobuf REQUIRED)


add_subdirectory(${FORMULA_AV_SOURCE_DIR}/proto)
# add_subdirectory(sensors)