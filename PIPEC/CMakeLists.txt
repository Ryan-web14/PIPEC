cmake_minimum_required(VERSION 3.10)

project(PIPEC VERSION 1.0)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("C:/Users/user/OneDrive/JoJo_personal/OneDrive/Bureau/PIPEC/PIPEC/Connector C++ 8.0/include/jdbc")
link_directories("C:/Users/user/OneDrive/JoJo_personal/OneDrive/Bureau/PIPEC/PIPEC/Connector C++ 8.0/lib64")

link_libraries(PIPEC mysqlcppcon)

add_subdirectory(src)
