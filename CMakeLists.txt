cmake_minimum_required(VERSION 3.0)

project(chigraph)

cmake_policy(SET CMP0053 NEW)

set(CG_THIRDPARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/)

option(CG_BUILD_TESTS "Should unit tests be built?" ON)
option(CG_BUILD_GUI "Should the GUI be built" ON)
option(CG_LINK_FFI "Should FFI be linked in--llvm sometimes forgets to link it" ON)
option(CG_BUILD_DEBUGGER "Should the debugger be built" ON)

# this is really important to keep install-like paths
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# disable tests
set(BUILD_CLAR OFF CACHE BOOL "")
add_subdirectory(third_party/libexecstream)

# we're building them ourselves, so don't auto-link in on windows
add_definitions("-DBOOST_ALL_NO_LIB")
add_subdirectory(third_party/boost)

# find llvm-config. This dictates which clang etc is uses. 
# Clang MUST be installed in the same directory.
find_program(LLVM_CONFIG llvm-config REQUIRED)
message(STATUS "llvm-config found at ${LLVM_CONFIG}")

execute_process(COMMAND ${LLVM_CONFIG} --version OUTPUT_VARIABLE LLVM_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
message(STATUS "LLVM version: ${LLVM_VERSION}")

# add libchig
add_subdirectory(libchig)

if (CG_BUILD_DEBUGGER)
	add_subdirectory(libchigdebugger)
endif()

add_subdirectory(chig)

if(CG_BUILD_GUI)
	set(BUILD_EXAMPLES OFF CACHE BOOL "")
	add_subdirectory(third_party/nodeeditor)
	add_subdirectory(gui)
endif()

# Unit tests...
if(CG_BUILD_TESTS)
	enable_testing()
	add_subdirectory(test)
endif()

# Documentation

find_package(Doxygen)

if(DOXYGEN_FOUND)
	
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in ${CMAKE_BINARY_DIR}/Doxyfile)
	
	add_custom_target(doc
		COMMAND ${DOXYGEN_EXECUTABLE}
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
		COMMENT "Generating Doxygen Docs..."
		DEPENDS ${CHIGRAPH_PRIVATE_FILES} ${CHIGRAPH_PUBLIC_FILES}
	)
	
else()
	message(WARNING "DOXYGEN not found, target `doc` will not be avaliable")
endif()

