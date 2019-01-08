cmake_minimum_required(VERSION 3.5)
project(autodiff)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

# checking for packages
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

# setting compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wno-sign-compare -Wno-unused-variable -Wno-return-type -Wno-unused-function --std=c++11")
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

# create custom command for flex/lex (note the outputs)
add_custom_command(
        COMMAND ${FLEX_EXECUTABLE}
        ARGS -o ${PROJECT_SOURCE_DIR}/parser/lexer.c
        ${PROJECT_SOURCE_DIR}/parser/lexer.l
        DEPENDS ${PROJECT_SOURCE_DIR}/parser/lexer.l
        OUTPUT  ${PROJECT_SOURCE_DIR}/parser/lexer.c
        COMMENT "Generating ${PROJECT_SOURCE_DIR}/parser/lexer.c"
)

# create custom command for bison/yacc (note the DEPENDS)
add_custom_command(
        COMMAND ${BISON_EXECUTABLE}
        ARGS -d -y ${PROJECT_SOURCE_DIR}/parser/parser.y
        -o ${PROJECT_SOURCE_DIR}/parser/parser.c
        DEPENDS ${PROJECT_SOURCE_DIR}/parser/lexer.c
        DEPENDS ${PROJECT_SOURCE_DIR}/parser/parser.y
        OUTPUT  ${PROJECT_SOURCE_DIR}/parser/parser.c
        COMMENT "Generating ${PROJECT_SOURCE_DIR}/parser/parser.c"
)

# setting propeties for the generated lexer and parser files
set_source_files_properties(${PROJECT_SOURCE_DIR}/parser/parser.c GENERATED PROPERTIES LANGUAGE CXX)
set_source_files_properties(${PROJECT_SOURCE_DIR}/parser/lexer.c GENERATED PROPERTIES LANGUAGE CXX)

include_directories("${PROJECT_SOURCE_DIR}/")
include_directories("${PROJECT_SOURCE_DIR}/parser")

set(SOURCE_FILES main.cpp model.cpp model.h parser/lexer.c parser/parser.c input.h exprtk.hpp input.cpp input.cpp a13x.cpp a13xBack.cpp)

add_executable(autodiff ${SOURCE_FILES})
target_link_libraries(autodiff -lfl)

