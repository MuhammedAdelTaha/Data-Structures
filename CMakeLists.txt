cmake_minimum_required(VERSION 3.25)
project(data_structures)

set(CMAKE_CXX_STANDARD 17)

add_executable(data_structures main.cpp ArrayBasedStack.cpp LinkedStack.cpp ArrayBasedQueue.cpp LinkedQueue.cpp BinarySearchTree.cpp)
