cmake_minimum_required(VERSION 3.20)

# Set the project name and version
# project(AdvancedCpp VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_subdirectory(Examples/DIP)
add_subdirectory(Examples/Folding)
add_subdirectory(Examples/ifinit)
add_subdirectory(Examples/modules)
add_subdirectory(Examples/MoveCtorExample)
add_subdirectory(Examples/Templates)
add_subdirectory(Examples/variance)
add_subdirectory(Solutions/Features)
add_subdirectory(Solutions/PayrollPart1)
add_subdirectory(Solutions/PayrollPart2)
add_subdirectory(Solutions/PayrollPart3)
add_subdirectory(Solutions/PayrollPart4)
add_subdirectory(Solutions/PayrollPart5)
add_subdirectory(Solutions/PayrollPart6)
add_subdirectory(Solutions/Factory)
add_subdirectory(Solutions/OperatorOverloading)
add_subdirectory(Solutions/Lambda)
add_subdirectory(Solutions/Composite)
add_subdirectory(Solutions/SmartPtrs)
add_subdirectory(Solutions/TemplateMethod)
add_subdirectory(Solutions/Threads)
add_subdirectory(Solutions/Tasks)