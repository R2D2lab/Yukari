# Yukari

[![Build Status](https://travis-ci.com/DanNixon/Yukari.svg?token=hEeXj1er91qf6vBmhf9x&branch=master)](https://travis-ci.com/DanNixon/Yukari)

3D environment mapper

## Building on Ubuntu 16.04

1. Install `libproj-dev libboost-all-dev libpcl1.7 libpcl-dev libeigen3-dev`
2. `cmake ../Yukari -DCMAKE_BUILD_TYPE=Debug -DBOOST_LIBRARYDIR=/usr/lib/x86_64-linux-gnu/`
3. `make`

## Building on Windows

For MSVC 14.

1. Install/build PCL and dependencies
  - Boost
    - https://github.com/boostorg/boost
    - 1.60.0
    - prebuilt
  - Eigen
    - https://github.com/RLovelett/eigen
    - 3.2.8
    - `cmake ../eigen`
    - `INSTALL`
  - FLANN
    - https://github.com/mariusmuja/flann
    - 1.9.1
    - `cmake ../flann`
    - `ALL_BUILD`
    - `INSTALL`
  - VTK
    - https://github.com/Kitware/VTK
    - 7.0.0
    - `cmake ../VTK -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=OFF`
    - `ALL_BUILD`
    - `INSTALL`
  - Copy `VTKConfig.cmake` to VTK root directory (e.g. `C:\Program Files\VTK`)
  - QHull
    - https://github.com/qhull/qhull
    - `master`
    - `cmake ../qhull`
    - `ALL_BUILD`
    - `INSTALL`
  - PCL
    - https://github.com/PointCloudLibrary/pcl
    - 1.8.0
    - `cmake ../pcl -G "Visual Studio 14 2015 Win64" -DEIGEN_INCLUDE_DIR="C:\Program Files\Eigen\include\eigen3" -DBoost_INCLUDE_DIR="C:\local\boost_1_60_0" -DBoost_LIBRARY_DIR="C:\local\boost_1_60_0\lib64-msvc-14.0" -DVTK_DIR="C:\Program Files\VTK"`
    - `ALL_BUILD`
    - `INSTALL`
2. `cmake ../Yukari -G "Visual Studio 14 2015 Win64" -DCMAKE_BUILD_TYPE=Debug -DBoost_INCLUDE_DIR="C:\local\boost_1_60_0" -DBoost_LIBRARY_DIR="C:\local\boost_1_60_0\lib64-msvc-14.0" -DVTK_DIR="C:\Program Files\VTK"`
