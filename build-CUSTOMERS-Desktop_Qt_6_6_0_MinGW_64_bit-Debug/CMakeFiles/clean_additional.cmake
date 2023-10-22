# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CUSTOMERS_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CUSTOMERS_autogen.dir\\ParseCache.txt"
  "CUSTOMERS_autogen"
  )
endif()
