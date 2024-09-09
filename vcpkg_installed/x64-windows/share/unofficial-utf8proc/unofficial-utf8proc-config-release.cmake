get_filename_component(VCPKG_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)
#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "utf8proc" for configuration "Release"
set_property(TARGET utf8proc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(utf8proc PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${VCPKG_IMPORT_PREFIX}/lib/utf8proc.lib"
  IMPORTED_LOCATION_RELEASE "${VCPKG_IMPORT_PREFIX}/bin/utf8proc.dll"
  )

list(APPEND _cmake_import_check_targets utf8proc )
list(APPEND _cmake_import_check_files_for_utf8proc "${VCPKG_IMPORT_PREFIX}/lib/utf8proc.lib" "${VCPKG_IMPORT_PREFIX}/bin/utf8proc.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
