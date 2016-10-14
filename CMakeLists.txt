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
set (TRIAL_INC_CORE ${CMAKE_CURRENT_SOURCE_DIR}/include/core/core.h)
set (TRIAL_INC_COLLECTIONS 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/collections/linked_list.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/collections/impl/linked_list.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/collections/bst.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/collections/impl/bst.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/collections/rbtree.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/collections/impl/rbtree.hpp
)

set (TRIAL_SRC_CORE ${CMAKE_CURRENT_SOURCE_DIR}/src/core/core.cpp)
set (TRIAL_SRC_MAIN ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)



#===============#
# Filter Groups #
#===============#
source_group(include\\core FILES ${TRIAL_INC_CORE})
source_group(include\\collections FILES ${TRIAL_INC_COLLECTIONS})
source_group(src FILES ${TRIAL_SRC_MAIN})
source_group(src\\core FILES ${TRIAL_SRC_CORE})
source_group(src\\collections FILES ${TRIAL_SRC_COLLECTIONS})



#=================#
# Header Includes #
#=================#
include_directories(include)


add_executable (trial 
	${TRIAL_INC_CORE} 
	${TRIAL_INC_COLLECTIONS}
	${TRIAL_SRC_CORE}
	${TRIAL_SRC_COLLECTIONS}
	${TRIAL_SRC_MAIN}
)
