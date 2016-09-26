cmake_minimum_required (VERSION 2.8)
##
## CMakeLists for trial project
##
## Copyright (c) 2016, KDuncan
## All Rights Reserved.
##
##----------------------------------------------------#
project (trial)


#=====================#
# Headers and Sources #
#=====================#
set (TRIAL_INC_CORE ${CMAKE_CURRENT_SOURCE_DIR}/include/core/core.hpp)
set (TRIAL_INC_DATA_STRUCTS ${CMAKE_CURRENT_SOURCE_DIR}/include/datastructures/linked_list.hpp)

set (TRIAL_SRC_CORE ${CMAKE_CURRENT_SOURCE_DIR}/src/core/core.cpp)
set (TRIAL_SRC_DATA_STRUCTS ${CMAKE_CURRENT_SOURCE_DIR}/src/datastructures/linked_list.cpp)


#===============#
# Filter Groups #
#===============#
source_group(include/core FILES ${TRIAL_INC_CORE})
source_group(include/datastructures FILES ${TRIAL_INC_DATA_STRUCTS})

source_group(src/core FILES ${TRIAL_SRC_CORE})
source_group(src/datastructures FILES ${TRIAL_SRC_DATA_STRUCTS})
source_group(src FILES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)


#=================#
# Header Includes #
#=================#
include_directories(include)


add_executable (trial src/main.cpp 
	${TRIAL_INC_CORE} 
	${TRIAL_INC_DATA_STRUCTS}
	${TRIAL_SRC_CORE}
	${TRIAL_SRC_DATA_STRUCTS}
)