cmake_minimum_required(VERSION 3.1)
project(SAPER)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)


add_executable(SAPER
    CMakeLists.txt
    main.cpp
    MinesweeperBoard.cpp
    MinesweeperBoard.h
    MSBoardTextView.cpp
    MSBoardTextView.h
    MSTextController.cpp
    MSTextController.h MSSFMLView.cpp MSSFMLView.h)
# Detect and add SFML
set(SFML_PATH "C:/cpp/SFML-2.5.1" ${CMAKE_MODULE_PATH})
set(SFML_DIR ${SFML_PATH}/lib/cmake/SFML)
find_package(SFML 2 REQUIRED graphics window system)

if(SFML_FOUND)
    target_link_libraries(SAPER sfml-graphics sfml-window sfml-audio)

endif()
