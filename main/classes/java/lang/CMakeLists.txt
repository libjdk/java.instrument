#machine generated

add_subdirectory("instrument")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.java.lang_SRCS)
file(GLOB classes.java.lang_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.java.lang_HEADERS}) 
list(LENGTH classes.java.lang_SRCS classes.java.lang_SRCS_LENGTH)
if(classes.java.lang_SRCS_LENGTH)
	add_library(classes.java.lang OBJECT "${classes.java.lang_SRCS}" "${classes.java.lang_HEADERS}")
	jcpp_enable_bigobj(classes.java.lang)
endif()