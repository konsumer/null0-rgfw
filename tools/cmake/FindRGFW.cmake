FetchContent_Declare(rgfw
  URL https://github.com/ColleagueRiley/RGFW/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(rgfw)
# add_definitions(-DRGFW_IMPLEMENTATION)
include_directories(${rgfw_SOURCE_DIR})

