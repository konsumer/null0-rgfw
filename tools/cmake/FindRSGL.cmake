FetchContent_Declare(rgsl
  URL https://github.com/ColleagueRiley/RSGL/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(rgsl)

add_definitions(-DRSGL_IMPLEMENTATION)
include_directories(${rsgl_SOURCE_DIR})
