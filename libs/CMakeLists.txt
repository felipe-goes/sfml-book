add_subdirectory(sfml)

# SDL
set(LIBS)
list(APPEND LIBS sfml-system)
list(APPEND LIBS sfml-window)
list(APPEND LIBS sfml-audio)
list(APPEND LIBS sfml-graphics)
# list(APPEND LIBS sfml-network)

add_library(libs INTERFACE)
target_link_libraries(libs INTERFACE ${LIBS})
