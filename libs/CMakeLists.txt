add_subdirectory(sfml)

# SFML
set(SFML)
list(APPEND SFML sfml-system)
list(APPEND SFML sfml-window)
list(APPEND SFML sfml-audio)
list(APPEND SFML sfml-graphics)
# list(APPEND SFML sfml-network)

add_library(sfml INTERFACE)

target_link_libraries(sfml INTERFACE ${SFML})
