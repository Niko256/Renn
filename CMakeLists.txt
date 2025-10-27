cmake_minimum_required(VERSION 3.30)

project(Renn LANGUAGES CXX)

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(RENN_SRC
  src/Runtime/Scheduler.cc
)

ADD_LIBRARY(Renn STATIC ${RENN_SRC})

TARGET_INCLUDE_DIRECTORIES(Renn PUBLIC include)

TARGET_COMPILE_FEATURES(Renn PUBLIC cxx_std_23)
TARGET_COMPILE_OPTIONS(Renn PRIVATE
  -Wall
  -Wextra
  -Wpedantic
)

ADD_EXECUTABLE(main src/main.cc)
TARGET_LINK_LIBRARIES(main PRIVATE Renn)
TARGET_COMPILE_FEATURES(main PRIVATE cxx_std_23)

INCLUDE(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0
)
# FIND_PACKAGE(Boost)

FetchContent_MakeAvailable(googletest)
ENABLE_TESTING()
ADD_SUBDIRECTORY(tests)
