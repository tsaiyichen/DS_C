cmake_minimum_required(VERSION 3.28)
project(DS_C C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_executable(main main.c)
add_executable(stack stack.c)
add_executable(queue queue.c)
add_executable(queueC queue_circular.c)
add_executable(QandS queue_stack.cpp)
add_executable(binaryTree Ch5/binaryTree.cpp)
