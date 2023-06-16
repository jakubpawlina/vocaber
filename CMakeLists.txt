cmake_minimum_required(VERSION 3.25)
project(vocaber)

set(CMAKE_CXX_STANDARD 20)

find_package(wxWidgets REQUIRED COMPONENTS core base)

# Include wxWidgets headers
include(${wxWidgets_USE_FILE})

# Set source files for project
set(SOURCES
        include/nlohmann/json.hpp
        src/App.cpp src/App.h
        src/MainFrame.cpp src/MainFrame.h
        src/LearnFrame.cpp src/LearnFrame.h
        src/utilities/validate_json_input.cpp src/utilities/validate_json_input.h)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link against wxWidgets libraries
if (wxWidgets_STATIC_LIBS)
    target_compile_definitions(${PROJECT_NAME} PRIVATE WX_USE_STATIC)
endif()

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
