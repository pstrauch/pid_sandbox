cmake_minimum_required(VERSION 3.0.0)
project(pid_sandbox VERSION 0.1.0)

#build these subdirectories
add_subdirectory(model)
add_subdirectory(project)
add_subdirectory(controller)