add_executable(pid_sandbox main.cpp)

#add the library
target_link_libraries(pid_sandbox PRIVATE 
model_lib
controller_lib)

target_include_directories(pid_sandbox PUBLIC
    ${PROJECT_SOURCE_DIR}/controller
    ${PROJECT_SOURCE_DIR}/model)