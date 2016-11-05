cmake_minimum_required (VERSION 2.8)
##
## CMakeLists for Rehearsal Project
##
## Copyright (c) 2016, KDuncan
## All Rights Reserved.
##
##----------------------------------------------------#
project (rehearsal)

#===========================#
# Set project to use C++ 11 #
#===========================#
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#=====================#
# Headers and Sources #
#=====================#
set (REHEARSAL_INC_CORE ${CMAKE_CURRENT_SOURCE_DIR}/include/core/core.h)
set (REHEARSAL_INC_COLLECTIONS 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/collections/linked_list.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/collections/impl/linked_list.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/collections/bst.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/collections/impl/bst.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/collections/rbtree.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/collections/impl/rbtree.hpp
)
set (REHEARSAL_INC_SOLUTIONS 
	${CMAKE_CURRENT_SOURCE_DIR}/include/solutions/two_element_sum.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/solutions/random_element_set.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/solutions/lru_cache.h
)
set (REHEARSAL_SRC_CORE ${CMAKE_CURRENT_SOURCE_DIR}/src/core/core.cpp)
set (REHEARSAL_SRC_SOLUTIONS 
	${CMAKE_CURRENT_SOURCE_DIR}/src/solutions/test_two_element_sum.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/solutions/test_random_element_set.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/solutions/test_lru_cache.cpp
)
set (REHEARSAL_SRC_MAIN ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)



#===============#
# Filter Groups #
#===============#
source_group(include\\core FILES ${REHEARSAL_INC_CORE})
source_group(include\\collections FILES ${REHEARSAL_INC_COLLECTIONS})
source_group(include\\solutions FILES ${REHEARSAL_INC_SOLUTIONS})
source_group(src FILES ${REHEARSAL_SRC_MAIN})
source_group(src\\core FILES ${REHEARSAL_SRC_CORE})
source_group(SRC\\solutions FILES ${REHEARSAL_SRC_SOLUTIONS})



#=================#
# Header Includes #
#=================#
include_directories(include)


add_executable (rehearsal 
	${REHEARSAL_INC_CORE} 
	${REHEARSAL_INC_COLLECTIONS}
	${REHEARSAL_INC_SOLUTIONS}
	${REHEARSAL_SRC_CORE}
	${REHEARSAL_SRC_SOLUTIONS}
	${REHEARSAL_SRC_MAIN}
)

#============================#
# Set compiler to use C++ 11 #
#============================#
set_property(TARGET rehearsal PROPERTY CXX_STANDARD 11)
