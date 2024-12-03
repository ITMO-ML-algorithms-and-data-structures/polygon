find_path(CUNIT_INCLUDE_DIRS CUnit/Basic.h PATHS "C:/msys64/mingw64/include")
find_library(CUNIT_LIBRARIES NAMES cunit PATHS "C:/msys64/mingw64/lib")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CUnit
        REQUIRED_VARS CUNIT_LIBRARIES CUNIT_INCLUDE_DIRS)

if(CUNIT_FOUND)
    add_library(CUnit::CUnit SHARED IMPORTED)
    set_target_properties(CUnit::CUnit PROPERTIES
            IMPORTED_LOCATION "${CUNIT_LIBRARIES}"
            INTERFACE_INCLUDE_DIRECTORIES "${CUNIT_INCLUDE_DIRS}")
else()
    message(FATAL_ERROR "CUnit not found. Please install it or set paths manually.")
endif()


