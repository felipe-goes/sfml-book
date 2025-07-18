add_library(Game STATIC Game.cpp Snake.cpp World.cpp)
set_target_properties(Game PROPERTIES DEBUG_POSTFIX d)

# add libraries include directories
target_include_directories(Game PRIVATE "${CMAKE_SOURCE_DIR}/include"
                                        "${CMAKE_SOURCE_DIR}/libs/sfml/include")

# state that anybody linking to us needs to include the source directory
target_include_directories(
  Game INTERFACE $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
                 $<INSTALL_INTERFACE:include>)

# link Game to project_flags
target_link_libraries(
  Game
  PUBLIC project_flags
  PRIVATE Graphics)

# install libs
set(installable_libs Game project_flags)
install(
  TARGETS ${installable_libs}
  EXPORT Game
  DESTINATION game)
