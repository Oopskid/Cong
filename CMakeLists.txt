if(NOT DEFINED CMGym_DIR)
   set(CMGym_DIR "${CMAKE_CURRENT_LIST_DIR}/../CMakeGym" CACHE STRING "The top directory of CMGym")
endif()

include(${CMGym_DIR}/scripts/core.cmake)

startLib(Cong)

addIncludesAuto(${CMAKE_CURRENT_LIST_DIR}/src CMFT_SRC_c++ Source)
addIncludesAuto(${CMAKE_CURRENT_LIST_DIR}/include CMFT_HEADER_c++ Headers)

add_library(Cong STATIC "${INCLUDES}")
bindIncludes(Cong)

endLib(Cong)