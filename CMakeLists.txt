cmake_minimum_required (VERSION 2.8)
project (timedrun)
set(INCLUDE_DIR .)
include_directories (${INCLUDE_DIR})
SET(ECHO "/bin/echo")
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    SET(BUILD_SHARED_LIBRARIES OFF)
    SET(CMAKE_EXE_LINKER_FLAGS "-static")
    SET(TRUE "/bin/true")
    add_library(timedrun-static STATIC timedrun.c)
    add_executable(timedrun main.c)
    target_link_libraries(timedrun timedrun-static)
ENDIF()
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    add_executable(timedrun main.c timedrun.c)
    SET(TRUE "/usr/bin/true")
ENDIF()


enable_testing()
add_test(true1 ./timedrun 1 ${TRUE})
add_test(true2 ./timedrun 2 ${TRUE})
add_test(echo ./timedrun 1 ${ECHO})
add_test(echo1 ./timedrun 1 ${ECHO} arg1)
add_test(echo2 ./timedrun 1 ${ECHO} arg1 arg2)
install (TARGETS timedrun DESTINATION bin)
add_custom_target(uninstall
   COMMAND -rm /usr/local/bin/timedrun
)
add_custom_target(dev
   COMMAND make clean
   COMMAND make
   COMMAND make test
)
