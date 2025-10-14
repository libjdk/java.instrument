#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.instrument_SRCS)
file(GLOB classes.sun.instrument_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.instrument_HEADERS}) 
list(LENGTH classes.sun.instrument_SRCS classes.sun.instrument_SRCS_LENGTH)
if(classes.sun.instrument_SRCS_LENGTH)
	add_library(classes.sun.instrument OBJECT "${classes.sun.instrument_SRCS}" "${classes.sun.instrument_HEADERS}")
	jcpp_enable_bigobj(classes.sun.instrument)
endif()