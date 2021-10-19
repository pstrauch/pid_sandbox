add_executable(pid_sandbox main.cpp)

#add the library
target_link_libraries(pid_sandbox PUBLIC model_lib)
target_link_libraries(pid_sandbox PUBLIC controller_lib)

#library header can be found
target_include_directories(pid_sandbox PUBLIC 
                            "${CMAKE_SOURCE_DIR}/model"
                            "${CMAKE_SOURCE_DIR}/controller")

#target_include_directories(pid_sandbox PUBLIC 
#                            "${CMAKE_SOURCE_DIR}/controller")