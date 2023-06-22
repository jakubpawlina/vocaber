cmake_minimum_required(VERSION 3.25)
project(vocaber)

set(CMAKE_CXX_STANDARD 20)

if (DEBUG)
    set(CMAKE_CXX_FLAGS "-DDEBUG")
endif()

find_package(wxWidgets REQUIRED COMPONENTS core base)

include(${wxWidgets_USE_FILE})

set(SOURCES
        include/nlohmann/json.hpp
        src/App.cpp src/App.h
        src/MainFrame.cpp src/MainFrame.h
        src/LearnFrame.cpp src/LearnFrame.h
        src/FinishFrame.cpp src/FinishFrame.h
        src/classes/Question.h
        src/utilities/validate_json_input.cpp src/utilities/validate_json_input.h
        src/utilities/get_json_from_file.cpp src/utilities/get_json_from_file.h
        src/utilities/load_questions_from_json.cpp src/utilities/load_questions_from_json.h
        src/utilities/scale_wx_bitmap.cpp src/utilities/scale_wx_bitmap.h
        src/defines/config_path.h
        )

add_executable(${PROJECT_NAME} ${SOURCES})

if (wxWidgets_STATIC_LIBS)
    target_compile_definitions(${PROJECT_NAME} PRIVATE WX_USE_STATIC)
endif()

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    install(TARGETS ${PROJECT_NAME} DESTINATION /usr/local/bin)
    install(DIRECTORY install/config DESTINATION /usr/local/share/vocaber)
    install(FILES install/vocaber.desktop DESTINATION /usr/share/applications)
endif()
