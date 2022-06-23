project(tests)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)
FILE(COPY sfml.png DESTINATION "${CMAKE_BINARY_DIR}/tests")


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}../cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

add_executable(tests CatchTests.cpp)
target_link_libraries(tests ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} Catch2::Catch2WithMain)