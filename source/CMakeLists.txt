add_subdirectory(inputs)
add_subdirectory(graphics)
add_subdirectory(game)

# add the executable
add_executable(${PROJECT_NAME} main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX
                                                 ${CMAKE_DEBUG_POSTFIX})

# link libraries
target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE libs project_flags
  PUBLIC Graphics Game Inputs)

# add the install targets
file(GLOB_RECURSE headers CONFIGURE_DEPENDS
     "${CMAKE_SOURCE_DIR}/include/*/*.hpp")
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES ${headers} DESTINATION include)
