cmake_minimum_required(VERSION 3.25)
project(vocaber)

set(CMAKE_CXX_STANDARD 20)

# Find wxWidgets package
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Include wxWidgets headers
include(${wxWidgets_USE_FILE})

# Set source files for project
set(SOURCES
        src/MainFrame.cpp src/MainFrame.h
        src/App.cpp src/App.h
        )

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link against wxWidgets libraries
if (wxWidgets_STATIC_LIBS)
    target_compile_definitions(${PROJECT_NAME} PRIVATE WX_USE_STATIC)
endif()

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
