cmake_minimum_required (VERSION 3.28)

project ("asmNotes" VERSION 0.1 LANGUAGES CXX ASM)

#For Windows. Enable Assembler language
enable_language(ASM_MASM)

set(SRC_PATH ${CMAKE_SOURCE_DIR})
set(ASM_PATH ${CMAKE_SOURCE_DIR}/asm)
set(INC_PATH ${CMAKE_SOURCE_DIR}/include)
set(SRC ${SRC_PATH}/main.cpp)
set(ASM ${ASM_PATH}/main.asm)
set(HRDS ${INC_PATH}/main.h)

#For asm files
set_property(SOURCE ${ASM} APPEND PROPERTY COMPOLE_OPTIONS "-x" "assembler-with-cpp")

add_executable (asmNotes ${SRC} ${ASM} ${HDRS})
target_include_directories(asmNotes PUBLIC ${ASM_PATH} ${INC_PATH})
