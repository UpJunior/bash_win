add_library(pwd SHARED pwd.cpp)

set(COMMAND_SOURCE
	pwd.cpp
)

add_executable(${PROJECT_NAME}
	main.cpp
	base.h
	register.h
	intf.h
	${COMMAND_SOURCE}

)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
	target_link_libraries(${PROJECT_NAME} dl)
endif()