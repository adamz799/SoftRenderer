# Install script for directory: F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/SDL2")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/Debug/SDL2-staticd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/Release/SDL2-static.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/MinSizeRel/SDL2-static.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/RelWithDebInfo/SDL2-static.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/Debug/SDL2d.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/Release/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/MinSizeRel/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/RelWithDebInfo/SDL2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/Debug/SDL2d.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/Release/SDL2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/MinSizeRel/SDL2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/RelWithDebInfo/SDL2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/Debug/SDL2maind.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/Release/SDL2main.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/MinSizeRel/SDL2main.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/RelWithDebInfo/SDL2main.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake"
         "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/CMakeFiles/Export/cmake/SDL2Targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/CMakeFiles/Export/cmake/SDL2Targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/CMakeFiles/Export/cmake/SDL2Targets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/CMakeFiles/Export/cmake/SDL2Targets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/CMakeFiles/Export/cmake/SDL2Targets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/CMakeFiles/Export/cmake/SDL2Targets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/SDL2Config.cmake"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/SDL2ConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_assert.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_atomic.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_audio.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_bits.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_blendmode.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_clipboard.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_config_android.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_config_iphoneos.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_config_macosx.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_config_minimal.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_config_os2.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_config_pandora.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_config_psp.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_config_windows.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_config_winrt.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_config_wiz.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_copying.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_cpuinfo.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_egl.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_endian.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_error.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_events.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_filesystem.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_gamecontroller.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_gesture.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_haptic.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_hints.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_joystick.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_keyboard.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_keycode.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_loadso.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_log.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_main.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_messagebox.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_mouse.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_mutex.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_name.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_opengl.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_opengl_glext.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_opengles.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_opengles2.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_opengles2_gl2.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_opengles2_gl2ext.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_opengles2_gl2platform.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_opengles2_khrplatform.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_pixels.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_platform.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_power.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_quit.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_rect.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_render.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_revision.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_rwops.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_scancode.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_sensor.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_shape.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_stdinc.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_surface.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_system.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_syswm.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_test.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_test_assert.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_test_common.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_test_compare.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_test_crc32.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_test_font.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_test_fuzzer.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_test_harness.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_test_images.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_test_log.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_test_md5.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_test_memory.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_test_random.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_thread.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_timer.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_touch.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_types.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_version.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_video.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/SDL_vulkan.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/begin_code.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/include/close_code.h"
    "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/include/SDL_config.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "F:/t/sync_file/文件/soft_renderer/SDL2-2.0.9/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
