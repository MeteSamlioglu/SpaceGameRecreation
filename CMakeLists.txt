cmake_minimum_required(VERSION 3.16)
project(SFML-Game)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)
set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

set(PROJECT_SOURCES
	    ${PROJECT_SOURCE_DIR}/Aircraft.cpp
            ${PROJECT_SOURCE_DIR}/Command.cpp
	    ${PROJECT_SOURCE_DIR}/CommandQueue.cpp
	    ${PROJECT_SOURCE_DIR}/Entity.cpp
	    ${PROJECT_SOURCE_DIR}/Game.cpp
	    ${PROJECT_SOURCE_DIR}/Player.cpp
	    ${PROJECT_SOURCE_DIR}/SceneNode.cpp
	    ${PROJECT_SOURCE_DIR}/SpriteNode.cpp
	    ${PROJECT_SOURCE_DIR}/World.cpp
            ${PROJECT_SOURCE_DIR}/main.cpp)
set(PROJECT_HEADERS
	    ${PROJECT_SOURCE_DIR}/Aircraft.hpp
	    ${PROJECT_SOURCE_DIR}/Category.hpp
 	    ${PROJECT_SOURCE_DIR}/Command.hpp
 	    ${PROJECT_SOURCE_DIR}/CommandQueue.hpp
 	    ${PROJECT_SOURCE_DIR}/Entity.hpp
 	    ${PROJECT_SOURCE_DIR}/Foreach.hpp
 	    ${PROJECT_SOURCE_DIR}/Game.hpp
 	    ${PROJECT_SOURCE_DIR}/Player.hpp
            ${PROJECT_SOURCE_DIR}/ResourceHolder.hpp
            ${PROJECT_SOURCE_DIR}/ResourceHolder.inl
            ${PROJECT_SOURCE_DIR}/SceneNode.hpp
            ${PROJECT_SOURCE_DIR}/SpriteNode.hpp
            ${PROJECT_SOURCE_DIR}/StringHelpers.hpp
	    ${PROJECT_SOURCE_DIR}/StringHelpers.inl
	    ${PROJECT_SOURCE_DIR}/World.hpp
            )

include_directories(${PROJECT_INCLUDE_DIR})
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics Threads::Threads)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM)
endif()

install(TARGETS ${PROJECT_NAME})
