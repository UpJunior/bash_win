add_library(pwd SHARED pwd.cpp)
add_executable(${PROJECT_NAME}
	main.cpp
	
	base.h
	register.h
	intf.h
	pwd.cpp
)
target_link_libraries(${PROJECT_NAME} dl)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../build/src/libpwd.so DESTINATION ${PUBLISH_OUTPUT})