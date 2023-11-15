cmake_minimum_required(VERSION 3.22)
project(expression C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")
add_executable(Graph src/include/expression_process.h src/lib/expression_process.c src/include/structs.h src/lib/structs.c src/graph.c)
target_link_libraries(Graph m)


file(GLOB_RECURSE HEADERS_INCLUDE "src/include/*.h*")
set(TARGET_NAME expression)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include(GNUInstallDirs)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_library(${TARGET_NAME} STATIC src/lib/expression_process.c src/include/expression_process.h src/lib/structs.c src/include/structs.h src/include/extern.h)
add_library(${TARGET_NAME}::${TARGET_NAME} ALIAS ${TARGET_NAME})

if (BUILD_SHARED_LIBS)
    target_compile_definitions(${TARGET_NAME} PUBLIC ${TARGET_NAME}_SHAREDLIB)
endif()

target_link_libraries(${TARGET_NAME} m)
target_compile_features(${TARGET_NAME} INTERFACE c_std_11)
target_include_directories(${TARGET_NAME}
        PRIVATE
        src/include
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>
        $<INSTALL_INTERFACE:include/${TARGET_NAME}>
        )

set_target_properties(${TARGET_NAME} PROPERTIES PUBLIC_HEADER "${HEADERS_INCLUDE}")
message("${HEADERS_INCLUDE}")
install(TARGETS ${TARGET_NAME}
        EXPORT ${TARGET_NAME}Targets DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${TARGET_NAME})

install(EXPORT ${TARGET_NAME}Targets
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${TARGET_NAME}/
        FILE ${TARGET_NAME}Targets.cmake
        NAMESPACE ${TARGET_NAME}::
        )

include(CMakePackageConfigHelpers)
configure_package_config_file(
        "${TARGET_NAME}Config.cmake.in"
        "${TARGET_NAME}Config.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${TARGET_NAME}
        PATH_VARS
        CMAKE_INSTALL_LIBDIR
)
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}ConfigVersion.cmake
        VERSION 1.0.0
        COMPATIBILITY SameMajorVersion
)
install(
        FILES "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}Config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}ConfigVersion.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${TARGET_NAME}"
)
include(CPack)