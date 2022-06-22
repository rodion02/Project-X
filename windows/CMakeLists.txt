cmake_minimum_required(VERSION 3.17)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled4 main.cpp)

include_directories(C:/Users/titan/SFML/include)

set(SFML_ROOT C:/Users/titan/SFML)
set(CMAKE_MODULE_PATH "C:/Users/titan/C++/untitled4/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(untitled4 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# Copy dlls to build
#if(WIN32)
#    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
#    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
#    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
#    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
#endif()