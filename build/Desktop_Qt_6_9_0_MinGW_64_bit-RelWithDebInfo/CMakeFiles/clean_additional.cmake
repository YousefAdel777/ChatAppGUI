# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles\\QtLearning_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QtLearning_autogen.dir\\ParseCache.txt"
  "QtLearning_autogen"
  )
endif()
