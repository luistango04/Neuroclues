# CMakeList.txt : CMake project for NEurotrees, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("NEurotrees")

# Add source to this project's executable.
add_executable (NEurotrees "NEurotrees.cpp" "NEurotrees.h"  "Tree.h"   "File.h" "csv.h" "xml.h" "config.h" "json.h")

# Include directories
target_include_directories(NEurotrees PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NEurotrees PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
