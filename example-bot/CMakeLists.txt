cmake_minimum_required(VERSION 2.8.4)
project(example-bot)

set(TgBot_INCLUDE_DIR $ENV{TgBot_INCLUDE_DIR})
set(TgBot_LIB $ENV{TgBot_LIB})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS ON)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system iostreams date_time locale REQUIRED)
include_directories(${TgBot_INCLUDE_DIR} ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR} ./src)

add_executable(example-bot src/main.cpp src/api.cpp src/engine.cpp src/keyboard.cpp src/utils.cpp)

target_link_libraries(example-bot ${TgBot_LIB} ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES})
