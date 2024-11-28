#!/bin/bash

# Check if the 'build' directory exists and delete it if it does
if [ -d "build" ]; then
    echo "Removing existing build directory..."
    rm -rf build
fi
# Create a new 'build' directory
echo "Creating a new build directory..."
mkdir build

# Check if the 'bin' directory exists and delete it if it does
if [ -d "bin" ]; then
    echo "Removing existing bin directory..."
    rm -rf bin
fi
# Create a new 'bin' directory
echo "Creating a new bin directory..."
mkdir bin

# Run cmake for the 'build' directory
echo "Running 'cmake' in the build directory..."
cmake -B build

# Run make in the 'build' directory
echo "Running 'make' in the build directory..."
make -C build
