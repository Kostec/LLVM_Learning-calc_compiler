cmake_minimum_required (VERSION 3.20.0)

project ("calc_compiler")
set(CMAKE_CXX_STANDARD 17)

# LLVM Start
find_package(LLVM REQUIRED CONFIG)
message("Found LLVM ${LLVM_PACKAGE_VERSION}, build type ${LLVM_BUILD_TYPE}")
list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})
include(DetermineGCCCompatible)
include(ChooseMSVCCRT)

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
include_directories(SYSTEM ${LLVM_INCLUDE_DIRS})
llvm_map_components_to_libnames(llvm_libs Core)

if(LLVM_COMPILER_IS_GCC_COMPATIBLE)
  if(NOT LLVM_ENABLE_RTTI)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
  endif()
  if(NOT LLVM_ENABLE_EH)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions")
  endif()
endif()
# LLVM End

# ANTLR Start
list(APPEND CMAKE_MODULE_PATH ${ANTLR_DIR})
find_package(ANTLR)
include_directories(SYSTEM ${ANTLR_INCLUDE_DIR})

message("ANTLR_INCLUDE_DIR: ${ANTLR_INCLUDE_DIR}")

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

add_subdirectory("Antlr_parser")
# ANTLR Start

# Target soueces
add_subdirectory ("src")

# Tool_templates
# TODO: find a way to create POST_BUILID event with copy these to target build directory
configure_file("${CMAKE_CURRENT_LIST_DIR}/templates/_calc_test.bat" "${CMAKE_CURRENT_LIST_DIR}/tools/gen/_calc_test.bat")
configure_file("${CMAKE_CURRENT_LIST_DIR}/templates/_calc_prepare.bat" "${CMAKE_CURRENT_LIST_DIR}/tools/gen/_calc_prepare.bat")

configure_file("${CMAKE_CURRENT_LIST_DIR}/templates/_calc_antlr_test.bat" "${CMAKE_CURRENT_LIST_DIR}/tools/gen/_calc_antlr_test.bat")
configure_file("${CMAKE_CURRENT_LIST_DIR}/templates/_calc_antlr_prepare.bat" "${CMAKE_CURRENT_LIST_DIR}/tools/gen/_calc_antlr_prepare.bat")

configure_file("${CMAKE_CURRENT_LIST_DIR}/templates/_compile.bat" "${CMAKE_CURRENT_LIST_DIR}/tools/gen/_compile.bat")