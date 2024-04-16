cmake_minimum_required(VERSION 3.27)
project(MyDX11)

set( GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE )

set(glfw_include_dir "path/to/libraries/GLFW/include")
set(glfw_lib_dir "path/to/libraries/GLFW/lib-vc2022")

set (CMAKE_CXX_STANDARD 20)

#find_package(glfw3 3.4 REQUIRED)


add_executable(MyDX11 Main.cpp
        Application.hpp Application.cpp
        HelloD3D11.hpp HelloD3D11.cpp)

target_include_directories(MyDX11 PRIVATE ${glfw_include_dir})
target_include_directories(MyDX11 PRIVATE ${glfw_lib_dir})

#Move GLFW libs to outbut dir.
add_custom_command(TARGET MyDX11 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            "${CMAKE_SOURCE_DIR}/lib/glfw3.dll"
            "${CMAKE_BINARY_DIR}/glfw3.dll")


target_link_libraries(MyDX11 d3d11.lib dxgi.lib d3dcompiler.lib
        winmm.lib dxguid.lib
        ${glfw_lib_dir}/glfw3dll.lib
        ${glfw_lib_dir}/glfw3.lib)

