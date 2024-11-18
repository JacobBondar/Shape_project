file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES} "../include/Rectangle.h" "Rectangle.cpp" "../include/triangle.h" "triangle.cpp" "../include/IsoscelesTriangle.h" "IsoscelesTriangle.cpp" "../include/Window.h" "Window.cpp")
