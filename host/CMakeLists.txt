find_package(RGFW)
find_package(RSGL)
find_package(physfs)

# copy a taget build-product to the webroot
function(COPY_TO_WEB name)
  add_custom_command(TARGET ${name} POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy
       "$<TARGET_FILE:${name}>"
       "${PROJECT_SOURCE_DIR}/docs/$<TARGET_FILE_NAME:${name}>")
endfunction()

add_executable(${PROJECT_NAME} src/main.c)

if (EMSCRIPTEN)
    target_link_libraries(${PROJECT_NAME} physfs-static)
    set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        SUFFIX ".mjs"
        COMPILE_FLAGS "-Oz"
        # add this for debugging: -sASSERTIONS=2
        LINK_FLAGS "-sFULL_ES3=1 -Oz -sUSE_WEBGL2=1 -sFORCE_FILESYSTEM -sASYNCIFY -sSINGLE_FILE -sMALLOC=emmalloc -sALLOW_MEMORY_GROWTH=1 -sEXPORTED_FUNCTIONS=_malloc,_free,_main"
    )
    COPY_TO_WEB(${PROJECT_NAME})
else()
    find_package(wamr)
    
    if(WIN32)
        target_link_libraries(${PROJECT_NAME} physfs-static vmlib opengl32 gdi32 shell32)
    elseif(APPLE)
        target_link_libraries(${PROJECT_NAME} physfs-static vmlib m "-framework Foundation" "-framework AppKit" "-framework OpenGL" "-framework CoreVideo")
    else()
        target_link_libraries(${PROJECT_NAME} physfs-static vmlib m GL dl pthread X11 Xrandr)
    endif()
endif()