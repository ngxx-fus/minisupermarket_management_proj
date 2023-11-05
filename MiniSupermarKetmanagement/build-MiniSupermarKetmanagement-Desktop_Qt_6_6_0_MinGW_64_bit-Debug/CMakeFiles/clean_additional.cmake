# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MiniSupermarKetmanagement_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MiniSupermarKetmanagement_autogen.dir\\ParseCache.txt"
  "MiniSupermarKetmanagement_autogen"
  )
endif()
