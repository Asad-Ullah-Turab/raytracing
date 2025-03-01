# Raytracing Project

This project is a simple ray tracing application using SDL2 for rendering.

## Project Structure

├── build/ # Build directory (generated)
├── include/ # Header files
│ └── circle.h
├── src/ # Source files
│ ├── circle.cpp
│ └── main.cpp
├── .gitignore # Git ignore file
├── CMakeLists.txt # CMake configuration file
├── Makefile # Makefile for building the project
└── Readme.md # Project documentation

## Dependencies

- SDL2

## Building the Project

To build the project, run the following commands:

```sh
cmake -S . -B build
cmake --build build
```

## Running the Project

To build and run the project, run the following commands:

```sh
make run
```

## Cleaning the project

To clean the build files, run:

```sh
make clean
```
