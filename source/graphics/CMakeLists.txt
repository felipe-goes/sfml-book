add_library(Graphics STATIC Window.cpp Textbox.cpp)
set_target_properties(Graphics PROPERTIES DEBUG_POSTFIX d)

# add libraries include directories
target_include_directories(
  Graphics PRIVATE "${CMAKE_SOURCE_DIR}/include"
                   "${CMAKE_SOURCE_DIR}/libs/sfml/include")

# state that anybody linking to us needs to include the source directory
target_include_directories(
  Graphics INTERFACE $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
                     $<INSTALL_INTERFACE:include>)

# link Graphics to project_flags
target_link_libraries(
  Graphics
  PUBLIC project_flags
  PRIVATE Inputs)

# install libs
set(installable_libs Graphics project_flags)
install(
  TARGETS ${installable_libs}
  EXPORT Graphics
  DESTINATION graphics)
