# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles\\ChatApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ChatApp_autogen.dir\\ParseCache.txt"
  "ChatApp_autogen"
  )
endif()
