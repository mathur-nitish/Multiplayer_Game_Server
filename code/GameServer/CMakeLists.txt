# CMakeList.txt : CMake project for GameServer, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (GameServer "GameServer.cpp" "GameServer.h")
target_include_directories(GameServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external/asio-1.30.2/include)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GameServer PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
