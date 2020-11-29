# CMake project for beginners

Hello! This repo is intended for developers attempting to learn C++. I've
created this project design so that it is both simple to use and demonstrates
some of the best practices for creating modern C++ projects.

Many of the C++ and CMake tutorials I've come across assume a high level
of experience with one or the other technology. These repos include macros,
bash build scripts, and many other intricacies. While these enhancements
definitely improve the developer experience, they also hide a lot of the
the fundamental components of CMake through automation. These are great
practices for production, but maybe not as clear for teaching purposes.

Also, please note that **I am a beginner at C++ and CMake too**. I happily
accept all thoughtful input and feedback on this project.

The main principles that I'm trying to observe in this project are:

 * **Simplicity.** The project contains eschews complicated macros or
   build scripts. The goal is to demonstrate the most basic CMake project.
 * **No IDE.** IDEs are wonderful tools. I have several that I'm partial
   towards. However, IDEs also obscure a lot of the underlying "magic" that
   transforms a project into an executable. Understanding how projects are
   compiled, how to establish relationships between different parts, how to
   target different operating systems, etc. is part of the learning process.
 * **Separation of concerns.** The project contains separate folders for the
   app executable, the source files of the app, external libraries, and tests.
 * **Test all source code.** Each part of the source code must have
   corresponding unit tests.
 * **Beginner-friendly.** The overall goal for this project is that a
   beginner-level C++ developer can create and extend a simple project that
   also exemplifies modern best practices with CMake.


## Prerequisites

Here is the environment and tools that I'm using for this project:

 * macOS Catalina (v10.15.7)
 * Unix build scripts
 * CMake (v3.19.1)
 * Apple clang (g++) (v12.0.0)
 * GoogleTest for testing (v1.10.0)
 * Sublime Text 2 as text editor

At the very minimum, you must have the following to follow along:

 * macOS
 * CMake CLI
 * Xcode command-line tools
 * Git

## Steps

This repo contains many of the files referenced in the following instructions
already. I provide these steps so that you can create your own project on
with the same structure as this repo.

**Note**: I have included code comments in the `CMakeLists.txt` files to help
describe what specific declarations actually *do*.

To create your own simple CMake project for C++ development, do the following:

 1. Make the project directories.

        mkdir {build,extern,app,src,test}

 1. Clone GoogleTest locally. This adds a folder for GoogleTest to the
    `extern` folder in the project. The `extern` folder is where to keep
    all of the external libraries you use in your project.

        cd extern
        git clone https://github.com/google/googletest/

 1. Create the main project `CMakeLists.txt`. Note that this sets the project
    name to `CMakePractice`--this string is prepended to your executables
    using the `${CMAKE_PROJECT_NAME}` variable.

        cmake_minimum_required(VERSION 3.10)
        project(CMakePractice)

        set(CMAKE_CXX_STANDARD 14)

        include_directories(app)

        add_subdirectory(app)
        add_subdirectory(src)
        add_subdirectory(test)
        add_subdirectory(extern/googletest)

 1. Create the app executable `CMakeLists.txt` in the `app/` folder. This is
    where to keep the `main()` method for the app.

        set(BINARY ${CMAKE_PROJECT_NAME})

        file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

        set(SOURCES ${SOURCES})

        add_executable(${BINARY} ${SOURCES})

        target_link_libraries(${CMAKE_PROJECT_NAME} LINK_PUBLIC src)

 1. Create the src library `CMakeLists.txt` in the `src/` folder. This is where
    to keep all of the source files for the project--classes, headers,
    utility functions, etc.

        file(GLOB_RECURSE LIB_SOURCES LIST_DIRECTORIES true *.h *.cpp)

        add_library(src STATIC ${LIB_SOURCES})

 1. Create the `CMakeLists.txt` file in the `test/` folder. This folder acts
    as a separate executable in your project from your main executable. Instead
    of running an app program, this executable instead runs your GoogleTest
    tests.

        set(BINARY ${CMAKE_PROJECT_NAME}_test)

        file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

        set(SOURCES ${TEST_SOURCES})

        add_executable(${BINARY} ${TEST_SOURCES})

        add_test(NAME ${BINARY} COMMAND ${BINARY})

        target_link_libraries(${BINARY} PUBLIC src gtest)

 1. Add your C++ code to the appropriate folders, as described in the previous
    steps. Take a look at the files in this repo for examples on how to include
    different pieces of the project into your code.

 1. Run the following command to generate the build artifacts and makefiles for
    the project. You should run this command from the `build/` folder.

        cd build
        cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"

 1. Make the project and test executables for the project. You need to invoke
    `make` in both the `app/` and the `test/` folder.

 1. Run the project (from the `build/` folder).

        ./app/CMakePractice

 1. Run the tests (from the `build/` folder).

        ./test/CMakePractice_test


## Resources

 * I've tried to model this project after the
   [folder project structure described here](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html).
 * I've borrowed heavily from
   [this blog post](https://raymii.org/s/tutorials/Cpp_project_setup_with_cmake_and_unit_tests.html).
 * All of the tests here use
   [GoogleTest](https://github.com/google/googletest/tree/master/googletest).