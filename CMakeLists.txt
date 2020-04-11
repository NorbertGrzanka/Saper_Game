project(untitled18)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(untitled18
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
    target_link_libraries(untitled18 sfml-graphics sfml-window sfml-audio)
    include_directories(${SFML_PATH}/include/SFML/)
endif()
