cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ShortestPath VERSION 0.1.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

find_package(Qt5 COMPONENTS REQUIRED
	Core
	Gui
	Widgets
	)
	
qt5_wrap_cpp(moc_src
	include/AppDialog.h
	)
	
qt5_wrap_ui(app_ui
	${CMAKE_CURRENT_SOURCE_DIR}/ui/appdialog.ui
	)
	
add_executable(${PROJECT_NAME}
	src/Application.cpp
	
	${moc_src}
	${app_ui}
	include/AppDialog.h
	src/AppDialog.cpp
	)
	
target_link_libraries(${PROJECT_NAME}
	PRIVATE
		Qt5::Core
		Qt5::Gui
		Qt5::Widgets
	)
	
target_include_directories(${PROJECT_NAME}
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/include
		${CMAKE_CURRENT_BINARY_DIR}
	)
	
if(WIN32)
add_custom_target(COPY_QT_DLLS ALL
	COMMENT "Deploying Qt Dlls..."
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:${PROJECT_NAME}>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:${PROJECT_NAME}>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:${PROJECT_NAME}>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::QWindowsIntegrationPlugin> $<TARGET_FILE_DIR:${PROJECT_NAME}>
	)
endif()
