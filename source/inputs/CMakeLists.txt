add_library(Inputs EventManager.cpp)

# add libraries include directories
target_include_directories(
  Inputs PRIVATE "${CMAKE_SOURCE_DIR}/include"
                 "${CMAKE_SOURCE_DIR}/libs/sfml/include")

# state that anybody linking to us needs to include the source directory
target_include_directories(
  Inputs INTERFACE $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
                   $<INSTALL_INTERFACE:include>)

# link Inputs to project_flags
target_link_libraries(Inputs PUBLIC project_flags)

# install libs
set(installable_libs Inputs project_flags)
install(
  TARGETS ${installable_libs}
  EXPORT Inputs
  DESTINATION inputs)
