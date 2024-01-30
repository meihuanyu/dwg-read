cmake_minimum_required(VERSION 3.20)
project("app" VERSION 0.1.0)


  
file(GLOB_RECURSE SRCS LIST_DIRECTORIES false app.cpp)
  # app程序
add_executable(app ${SRCS})
target_link_libraries(app PRIVATE proto)

  # app include path
#   target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# target_link_libraries(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/third_party/skia/out/wasm/libskia.a)