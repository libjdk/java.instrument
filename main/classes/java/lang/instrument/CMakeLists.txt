#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.java.lang.instrument_SRCS)
file(GLOB classes.java.lang.instrument_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.java.lang.instrument_HEADERS}) 
list(LENGTH classes.java.lang.instrument_SRCS classes.java.lang.instrument_SRCS_LENGTH)
if(classes.java.lang.instrument_SRCS_LENGTH)
	add_library(classes.java.lang.instrument OBJECT "${classes.java.lang.instrument_SRCS}" "${classes.java.lang.instrument_HEADERS}")
	jcpp_enable_bigobj(classes.java.lang.instrument)
endif()