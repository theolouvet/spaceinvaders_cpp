cmake_minimum_required(VERSION 2.6)

project(main)

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2 -std=c++11")


FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

file(
	GLOB
	source_files
        source/*.cpp
	include_files
        header/*.hpp
        header/*.h
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_UI(pgm_UI_H source/mainwindow.ui)
QT4_WRAP_CPP(source_files_moc header/window.hpp header/render_area.hpp)

add_executable(
	pgm
	${source_files}
	${pgm_UI_H}
	${source_files_moc}
)


TARGET_LINK_LIBRARIES(pgm -lm ${QT_LIBRARIES})


