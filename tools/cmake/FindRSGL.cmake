FetchContent_Declare(rsgl
  URL https://github.com/ColleagueRiley/RSGL/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(rsgl)
add_definitions(-DRSGL_IMPLEMENTATION)
include_directories(${rsgl_SOURCE_DIR})
